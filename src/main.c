#include <python3.11/Python.h>
#include <stdio.h>

int main() {
    // Simulated system performance data
    const char *performance_data =
        "2025-02-18 15:22,Sensor Read,140,2400,Success\\n"
        "2025-02-18 15:24,Data Sync,200,3100,Warning";

    printf("Initializing Python...\n");
    Py_Initialize();

    printf("Running Python code...\n");

    // Build a full Python script as one string
    char python_script[2048];
    snprintf(python_script, sizeof(python_script),
        "import csv\n"
        "from datetime import datetime\n"
        "data = \"Timestamp,Operation,ExecutionTime_ms,MemoryUsed_KB,Status\\n%s\"\n"
        "lines = data.strip().split('\\n')\n"
        "rows = [line.split(',') for line in lines]\n"
        "filename = f'report_{datetime.now().strftime(\"%%Y%%m%%d_%%H%%M%%S\")}.csv'\n"
        "with open(filename, 'w', newline='') as f:\n"
        "    writer = csv.writer(f)\n"
        "    writer.writerows(rows)\n"
        "print(f'Report written to {filename}')\n",
        performance_data);

    // Run the full script
    PyRun_SimpleString(python_script);

    printf("Finalizing Python...\n");
    Py_Finalize();

    printf("Python execution completed.\n");
    return 0;
}

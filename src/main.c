#include <python3.11/Python.h>
#include <stdio.h>

int main() {
    printf("Initializing Python...\n");
    Py_Initialize();

    // Open the Python script file
    FILE* fp = fopen("/var/tmp/script.py", "r");
    if (fp == NULL) {
        perror("Failed to open Python script");
        return 1;
    }

    printf("Running Python script from file...\n");
    PyRun_SimpleFile(fp, "/var/tmp/script.py");
    fclose(fp);

    Py_Finalize();
    printf("Python execution complete.\n");

    return 0;
}

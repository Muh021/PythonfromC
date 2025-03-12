import csv
from datetime import datetime

data = """Timestamp,Operation,ExecutionTime_ms,MemoryUsed_KB,Status
2025-03-12 14:25,SensorRead,140,2400,Success
2025-03-12 14:30,DataProcess,180,3100,Success
2025-03-12 14:35,SystemCheck,200,2900,Warning"""

# Split data into lines and parse rows
lines = data.strip().split('\n')
rows = [line.split(',') for line in lines]

# Create a timestamped filename
filename = f'report_{datetime.now().strftime("%Y%m%d_%H%M%S")}.csv'

# Write data to CSV file
with open(filename, 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerows(rows)

print(f'Report written to {filename}')

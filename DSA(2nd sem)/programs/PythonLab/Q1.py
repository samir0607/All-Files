import numpy as np
import pandas as pd

# Creating a 4x4 NumPy array with specific values
array_4x4 = np.array([[1, 2, 3, 4], 
                      [5, 6, 7, 8], 
                      [9, 10, 11, 12], 
                      [13, 14, 15, 16]])

# Converting the NumPy array to a Pandas DataFrame with custom labels
df = pd.DataFrame(array_4x4, columns=['A', 'B', 'C', 'D'], index=['Row1', 'Row2', 'Row3', 'Row4'])

# Calculating the mean of each row
row_means_labeled = df.mean(axis=1)

print(df)
print("\nMean of each row:")
print(row_means_labeled)

# Adding a new column 'E' by summing columns 'A' and 'B'
df['E'] = df['A'] + df['B']

print(df)
using System;

namespace KWeakestRows
{
    public class Program
    {
        public static void Main()
        {

            Solution answer = new Solution();

            int[][] test1 = new int[][]
            {
            new int[] {1,1,0,0,0},
            new int[] {1,1,1,1,0},
            new int[] {1,0,0,0,0},
            new int[] {1,1,0,0,0},
            new int[] {1,1,1,1,1}
            };

            int k1 = 3;

            int[] expected1 = { 2, 0, 3 };

            int[] results1 = answer.KWeakestRows(test1, k1);

            Console.WriteLine($"results match expected: " + (Enumerable.SequenceEqual(expected1,results1)));

            int[][] test2 = new int[][]
            {
            new int[] {1,0,0,0},
            new int[] {1,1,1,1},
            new int[] {1,0,0,0},
            new int[] {1,0,0,0}
            };

            int k2 = 2;

            int[] expected2 = { 0, 2 };

            int[] results2 = answer.KWeakestRows(test2, k2);

            Console.WriteLine($"results match expected: " + (Enumerable.SequenceEqual(expected2, results2)));

            int[][] test3 = new int[][]
            {
                new int[] { 1, 0 },
                new int[] { 1, 0 },
                new int[] { 1, 0 },
                new int[] { 1, 1 }
            };

            int k3 = 4;

            int[] expected3 = { 0,1,2,3 };

            int[] results3 = answer.KWeakestRows(test3, k3);

            Console.WriteLine($"results match expected: " + (Enumerable.SequenceEqual(expected3, results3)));

            int[][] test4 = new int[][]
            {
                new int[] {1, 1, 1, 0, 0, 0, 0 },
                new int[] {1, 1, 1, 1, 1, 1, 0 },
                new int[] {0, 0, 0, 0, 0, 0, 0 },
                new int[] {1, 1, 1, 0, 0, 0, 0 },
                new int[] {1, 1, 1, 1, 1, 1, 1 }
            };

            int k4 = 4;

            int[] expected4 = { 2, 0, 3, 1 };

            int[] results4 = answer.KWeakestRows(test4, k4);

            Console.WriteLine($"results match expected: " + (Enumerable.SequenceEqual(expected4, results4)));

    }
    }

    public class Solution
    {
        public int[] KWeakestRows(int[][] mat, int k)
        {

            int[] weakest = new int[k];
            int[] values = new int[mat.Length];

            for (int i = 0; i < k; i++)
            {
                values[i] = rowStrength(mat[i]);
                int j = 0;
                while (i > j && values[i] >= values[weakest[j]])
                {
                    j++;
                }

                if (i == j)
                {
                    weakest[j] = i;
                }
                else //values[i] < values[j], j < i;
                {
                    int temp = i;
                    while (temp > j)
                    {
                        weakest[temp] = weakest[--temp];
                    }
                    weakest[j] = i;
                }
            }

            for (int i = k; i < mat.Length; i++)
            {
                values[i] = rowStrength(mat[i]);

                if (values[i] < values[weakest[k - 1]])
                {

                    weakest[k - 1] = i;
                    int weakIndex = k - 2;

                    while (weakIndex >= 0 && values[i] < values[weakest[weakIndex]])
                    {
                        weakest[weakIndex + 1] = weakest[weakIndex];
                        weakest[weakIndex] = i;
                        weakIndex--;
                    }
                }
            }

            return weakest;

            int rowStrength(int[] row)
            {
                int i = 0;
                while (i < row.Length && row[i] == 1)
                {
                    i++;
                }
                return i;
            }
        }

    }
}
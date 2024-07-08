using System;

namespace Sort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 12, 11, 100, 20, 2 };
            // arr.SelectionSort("asc");
            arr.QuickSort(0, arr.Length - 1, "desc");
            foreach (var item in arr)
            {
                Console.Write(item + " ");
            }
        }
    }
}

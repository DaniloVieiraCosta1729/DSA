#!/usr/bin/env dotnet

using System.IO;
using System.Runtime.InteropServices;

namespace CsharpSort
{
	public class Program
	{
		public static void Swap(ref int x, ref int y)
		{
			int temp = x;
			x = y;
			y = temp;
		}

		public static void InsertionSort(Span<int> span)
		{
			for(int i = 0; i < span.Length - 1; i++)
			{
				int j = i + 1;
				while((j > 0) && (span[j - 1] > span[j]))
				{
					Swap(ref span[j - 1], ref span[j]);
					j--;
				}
			}
		}
		public static void Main(string[] arguments)
		{
			byte[] arrayInts = File.ReadAllBytes("numbers.bin");
			Span<byte> bspan = arrayInts;

			Span<int> ispan = MemoryMarshal.Cast<byte, int>(bspan);

			InsertionSort(ispan);
		}
	}
}

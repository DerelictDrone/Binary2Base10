using System;
using System.IO;
using System.Text;
namespace CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            if(args.Length == 0) {
				Console.WriteLine("Pass file name to convert");
				return;
			} else {
				string fileName = args[0];
				string newFileName = fileName.Split('.')[0] + ".txt";
				FileStream original = File.OpenRead(fileName);
				FileStream newFile = File.OpenWrite(newFileName);
				ulong size = (ulong)original.Length;
				ulong offset = 0;
				byte[] convertedText;
				byte[] buffer = new byte[4096];
				string[] stringChunk = new string[4096];
				string conversionString = "";
				while(original.Read(buffer,0,buffer.Length) > 0) {
					for(int i = 0; i < stringChunk.Length; i++) {
						stringChunk[i] = buffer[i].ToString();
					}
					conversionString = string.Join(" ",buffer);
					convertedText = Encoding.UTF8.GetBytes(conversionString);
					newFile.Write(convertedText,0,convertedText.Length);
					Console.Write("\r" + offset + " Bytes parsed of " + size);
					offset += (ulong)convertedText.Length;
				}
			}
        }
    }
}

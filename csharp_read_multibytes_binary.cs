using System;
using System.Collections.Generic;
using System.IO;

namespace ReadBinary
{
    class Program
    {
        static void Main(string[] args)
        {
            List<short> datas = new List<short>();

            using (FileStream fs = new FileStream(@"D:\ex2tron\Desktop\message.dat", FileMode.Open, FileAccess.Read))
            {
                using (BinaryReader br = new BinaryReader(fs))
                {
                    while (true)
                    {
                        try
                        {
                            datas.Add(br.ReadInt16());
                        }
                        catch (Exception)
                        {
                            break; //读取结束
                        }
                    }
                }
            }

            datas.ForEach(p => Console.WriteLine(p));
            Console.ReadKey();
        }
    }
}

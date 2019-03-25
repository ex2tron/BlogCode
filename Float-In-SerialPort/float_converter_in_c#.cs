/***************************
    ex2tron's Tech Blog:
    http://ex2tron.wang
    2019年3月25日
***************************/

using System;

namespace FloatInCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            /*** 大家感兴趣可以研究下BitConverter类的一些方法 ***/

            // 字节数组转浮点数：byte[] -> float
            byte[] recData = { 0xC3, 0XF5, 0X48, 0XC0 };
            float sensorData = BitConverter.ToSingle(recData, 0);
            Console.WriteLine(sensorData); // 结果：-3.14

            // 浮点数转字节数组：float -> byte[]
            float sData = -3.14f;
            byte[] rData = BitConverter.GetBytes(sData);
            foreach (byte data in rData) Console.Write("{0:X000},", data);

            // 结果：C3,F5,48,C0,
            // 判断大小端：Console.WriteLine(BitConverter.IsLittleEndian);

            Console.ReadKey();
        }
    }
}
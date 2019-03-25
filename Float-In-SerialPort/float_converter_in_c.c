/***************************
    ex2tron's Tech Blog:
    http://ex2tron.wang
    2019年3月25日
***************************/

#include <stdio.h>

int main()
{
    float sensorData = -3.14;
    unsigned char *arr = (unsigned char *)(&sensorData);
    printf("%02X,%02X,%02X,%02X\n", arr[0], arr[1], arr[2], arr[3]);
    // 结果：C3,F5,48,C0

    unsigned char charArr[4], i;
    for (i = 0; i < 4; i++)
        charArr[i] = *arr++;
    printf("%02X,%02X,%02X,%02X\n", charArr[0], charArr[1], charArr[2], charArr[3]);
    // 结果：C3,F5,48,C0

    unsigned char sBuf[4];
    sBuf[0] = 0xC3;
    sBuf[1] = 0xF5;
    sBuf[2] = 0x48;
    sBuf[3] = 0xC0;
    float *data = (float *)(&sBuf);
    printf("%f\n", *data); // 结果：-3.140000

    union {
        float data;
        unsigned char arr[4];
    } dataFormat;

    dataFormat.data = -3.14;
    printf("%02X,%02X,%02X,%02X\n", dataFormat.arr[0], dataFormat.arr[1], dataFormat.arr[2], dataFormat.arr[3]);
    // 结果：C3,F5,48,C0

    dataFormat.arr[0] = 0xC3;
    dataFormat.arr[1] = 0xF5;
    dataFormat.arr[2] = 0x48;
    dataFormat.arr[3] = 0xC0;
    printf("%f\n", dataFormat.data); // 结果：-3.140000

    return 0;
}
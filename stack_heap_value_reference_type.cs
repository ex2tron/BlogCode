#region 堆栈举例

//例1-1
public int AddFive(int num)
{
    int result;
    result = num + 5;
    return result;
}

//例1-2
public class Test
{
    public int Value { get; set; }
}

public Test AddFive(int num)
{
    Test result = new Test();
    result.Value = num + 5;
    return result;
}

#endregion


#region 值传递和引用传递

class Point
{
    public int X { get; set; }
    public int Y { get; set; }

    public Point(int x, int y)
    {
        X = x;
        Y = y;
    }
}

//例2
Point p1 = new Point(10, 20);
Point p2 = p1;
p2.X = 30;
p2.Y = 40;

Console.WriteLine(p1.X);
Console.WriteLine(p1.Y);

//例3
static void Func(Point p)
{
    p.X = 50;
    p.Y = 50;
    p = null;
}

Point p1 = new Point(10, 20);
Func(p1);
Console.WriteLine(p1.X);
Console.WriteLine(p1.Y);

//例4：引用传递
static void Func(ref Point p)
{
    p.X = 50;
    p.Y = 50;
    p = null;
}

Point p1 = new Point(10, 20);
Func(ref p1);
//此时，下面两句是否会报错？
Console.WriteLine(p1.X);
Console.WriteLine(p1.Y);

#endregion
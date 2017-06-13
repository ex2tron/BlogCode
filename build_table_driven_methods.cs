/* 博客：构建法、表驱动法
   ex2tron 2017年6月413日
   http://ex2tron.lofter.com */

/* 笨的方法：使用if/else或switch/case */
if (month == 1) day = 31;
else if (month == 2) day = 28;
else if (month == 3) day = 31;
else if (month == 4) day = 30;
else if (month == 5) day = 31;
else if (month == 6) day = 30;
else if (month == 7) day = 31;
else if (month == 8) day = 31;
else if (month == 9) day = 30;
else if (month == 10) day = 31;
else if (month == 11) day = 30;
else if (month == 12) day = 31;

/* 直接查表法
   简洁且优雅的方法  */
int[] daysPerMonth = new int[12] 
{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
day = daysPerMonth[month-1];

/* 直接查表法
   转换键值  */
int[] distBaseSpeed = { a, a,……a, n31, n32,……, n99, b, b,……, b };
newKey = Math.Max(Math.Min(100, speed), 30);

/* 阶梯查表法
   取区间的上限值  */
double[] scoreLimit = { 60.0, 70.0, 90.0, 100.0 };
string[] grade = { "不及格", "及格", "良", "优" };

int gradeLevel = 0;
string gradeResult = "优";
while (gradeResult == "优" && gradeLevel < grade.Length - 1)
{
    if (score < scoreLimit[gradeLevel])
        gradeResult = grade[gradeLevel];
    gradeLevel++;
}

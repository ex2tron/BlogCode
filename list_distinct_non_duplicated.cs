// C#中常用的集合去重方法

//要用到的Student类
class Student
{
    public int ID { get; set; }
    public string Name { get; set; }
}
//要用到的两个重复集合
List<int> numbers = new List<int>() { 1, 1, 2, 3, 2, 4, 2, 6 };
List<Student> students = new List<Student>
{
    new Student(){ID=1,Name="tony"},
    new Student(){ID=2,Name="alice"},
    new Student(){ID=1,Name="tony"},
};

// 方法一：使用集合的Distinct方法
var newNumbers = numbers.Distinct();

class StudentCompare : IEqualityComparer<Student>
{
    public bool Equals(Student x, Student y)
    {
        return x.ID == y.ID ? true : false;
    }

    public int GetHashCode(Student obj)
    {
        if (obj == null) return 0;
        else return obj.ToString().GetHashCode();
    }
}
var newStudents = students.Distinct(new StudentCompare());

// 方法二：利用LINQ
var newNumbers = numbers.Where((d, i) => numbers.FindIndex(p => p == d) == i);
var newStudents = students.Where((d, i) => students.FindIndex(p => p.ID == d.ID) == i);

//方法三：使用HashSet集合
HashSet<int> newNumbers = new HashSet<int>(numbers);

class Student
{
    public int ID { get; set; }
    public string Name { get; set; }

    public override bool Equals(object obj)
    {
        Student s = obj as Student;
        return this.ID == s.ID;
    }

    public override int GetHashCode()
    {
        return this.ID.GetHashCode();
    }
}
HashSet<Student> newStudents = new HashSet<Student>(students);

// 方法四：最土的方法——循环
List<int> newNumnbers = new List<int>(numbers.ToArray());
for (int i = 0; i < newNumnbers.Count; i++)
{
    for (int j = newNumnbers.Count - 1; j > i; j--)
    {
        if (newNumnbers[i]== newNumnbers[j])
        {
            newNumnbers.RemoveAt(j);
        }
    }
}

List<Student> newStudents = new List<Student>();
foreach (var student in students)
{
    if (!newStudents.Exists(p=>p.ID==student.ID))
    {
        newStudents.Add(student);
    }
}

//方法四（for循环和foreach循环都可以，如下：）
List<int> newNumbers = new List<int>();
foreach (var number in numbers)
{
    if (!newNumbers.Exists(p=>p==number))
    {
        newNumbers.Add(number);
    }
}

List<Student> newStudents = new List<Student>(students.ToArray());

for (int i = 0; i < newStudents.Count; i++)
{
    for (int j = newStudents.Count - 1; j > i; j--)
    {
        if (newStudents[i].ID==newStudents[j].ID)
        {
            newStudents.RemoveAt(j);
        }
    }
}
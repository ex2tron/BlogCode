//C#中集合List的深浅拷贝

List<int> nums1 = newList<int>() { 0, 1, 2 };
List<int> nums2 = nums1;

nums2[0]=3
System.Console.WriteLine(nums1[0]);


//一、T为值类型：
List<T> oldList = new List<T>();
oldList.Add(...);
//浅拷贝：
List<T> newList = oldList;
//深拷贝方式一：定义时传参
List<T> newList = new List<T>(oldList.ToArray());
// 深拷贝方式二：使用lambda表达式
List<T> newList = new List<T>();
oldList.ForEach(p => newList.Add(p));

//二、T为引用类型：
// 深拷贝方式一：实现ICloneable接口
class Student : ICloneable
{
   public int ID { get; set; }
   public string Name { get; set; }
 
   public object Clone()
   {
       Student nStu = new Student();
       nStu.ID = this.ID;
       nStu.Name = this.Name;
       return nStu;
   }
}

List<Student> stus = new List<Student>
{
   new Student{ID=1,Name="wang"},
   new Student{ID=2,Name="li"},
};
List<Student> stus2 = new List<Student>();
stus.ForEach(p => stus2.Add((Student)p.Clone()));
stus2[0].ID = 3;

//深拷贝方式二：使用序列化/反序列化方式
List<Student> stus = new List<Student>
{
   new Student{ID=1,Name="wang"},
   new Student{ID=2,Name="li"},
};

var oldJson= JsonConvert.SerializeObject(stus);
List<Student> stus2 = new List<Student>();
stus2.AddRange(JsonConvert.DeserializeObject<List<Student>>(oldJson));
stus2[0].ID = 3;
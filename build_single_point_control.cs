一、使用具名常量
//含义不明确，且不易修改的代码
int[] ReceivedDatas=new int[100];

//含义更加清晰，且易修改的代码
const int MAX_RECEIVED_LENGTH=100;
int[] ReceivedDatas=new int[MAX_RECEIVED_LENGTH];

二、使用结构体组织数据
//无组织，混乱的一堆变量
id=txtId;
name=txtName;
score=txtScore;
bonus=txtBonus;
department=txtDepartment;
payment=txtPayment;

//用结构体组织过的变量
student.id=txtId;
student.name=txtName;
student.score=txtScore;

employee.bonus=txtBonus;
employee.department=txtDepartment;
employee.payment=txtPayment;

//交换两组变量的值
tempid=id;
tempname=name;
tempscore=score;

id=newId;
name=newName;
score=newScore;

newId=tempid;
newName=tempname;
newScore=tempscore;

//使用结构体交换两组变量
struct Student
{
    public int id;
    public string name;
    public float score;
}
tempStudent = oldStudent;
oldStudent = newStudent;
newStudent = tempStudent;

//未使用结构体调用函数
DealStudent(int id,string name,float score,string phone,string address);

//使用结构体调用函数
DealStudent(Student student);
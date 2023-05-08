#include<iostream>
#include <string>
#include<fstream>
using namespace std;

template <typename t>
class arrays
{
public:
	int size;
	int index;
	t* arr;

	arrays()
	{
		size = 5;
		arr = new t[5];
		index = -1;
	}
	arrays(t data)
	{
		size = 5;
		arr = new t[5];

		index++;
		arr[index] = data;
	}

	void grow()
	{
		if (index == size)
		{
			size = size * 2;
			t* temp = new t[size];
			for (int i = 0; i <= index; i++)
			{
				temp[i] = arr[i];
			}
			delete[]arr;
			arr = temp;
		}
	}
	void decay()
	{
		if (index < (size / 2))
		{
			size = size / 2;
			t* temp = new t[size];
			for (int i = 0; i <= index; i++)
			{
				temp[i] = arr[i];
			}
			delete[]arr;
			arr = temp;
		}
	}
	void del_start()
	{
		for (int i = 0; i < index; i++)
		{
			arr[i] = arr[i + 1];
		}
		index--;
		decay();
	}
	void add_end(t data)
	{
		index++;
		grow();
		arr[index] = data;
	}
	void del_end()
	{
		index--;
		decay();
	}

	t get_start()
	{
		return arr[0];
	}
	t get_end()
	{
		return arr[index];
	}

	bool search(t data)
	{
		for (int i = 0; i < index + 1; i++)
		{
			if (data == arr[i])
				return true;
		}
		return false;
	}

	

	void print()
	{
		for (int i = 0; i <= index; i++)
			cout << arr[i] << "<--";
		cout << endl;
	}

	t operator[](int i)
	{
		return arr[i];
	}
};

using namespace std;
class Course
{
protected:

    char name[3];
    char discription[30];
    char* id=new char[4];
    
public:
    Course (){}
    Course(char n[3], char d[30], char i[4])
    {
        for (int x=0;x<3;x++)
            name[x]=n[x];
        for (int x=0;x<30;x++)
            discription[x]=d[x];
        for (int x = 0; x < 4; x++)
            id[x] = i[x];
    }

    void print()
    {
        for (int x = 0; x < 4; x++)
            cout << id[x];
        cout << endl;
        for (int x = 0; x < 3; x++)
            cout << name[x];
        cout << endl;
        for (int x = 0; x < 30; x++)
            cout << discription[x];
        cout << endl;
    }

    char* get_id()
    {
        /*string temp;
        temp = id[0] + id[1] + id[2] + id[3];*/
        return id;
    }

    void print_name()
    {
        for (int x = 0; x < 3; x++)
            cout << name[x];
        cout << "(";
        for (int x = 0; x < 4; x++)
            cout << id[x];
        cout << ")";
        
    }
};

class room
{
protected:
    char* rno = new char[4];
    char capacity[2];
    char tele_exe[3];

public:
    room(){}
    room(char r[4], char c[2], char t[3])
    {
        for (int x = 0; x < 4; x++)
            rno[x] = r[x];
        for (int x = 0; x < 2; x++)
            capacity[x] = c[x];
        for (int x = 0; x < 3; x++)
            tele_exe[x] = t[x];
    }

    void print()
    {
        for (int x = 0; x < 4; x++)
            cout << rno[x];
        cout << "    ";
        for (int x = 0; x < 2; x++)
            cout << capacity[x];
        cout << "    ";
        for (int x = 0; x < 3; x++)
            cout << tele_exe[x];
        cout << endl;
        
    }

    char* get_id()
    {
        return rno;
    }
};

class person
{
protected:
    char first_name[7];
    char last_name[7]; 
    char dob[10];

    char* id=new char[4];

public:
    person()
    {}
    person(char f[7],char l[7], char d[10], char i[4])
    {
        for (int x=0;x<7;x++)
        {
            first_name[x] = f[x];
            last_name[x] = l[x];
        }
        for (int x=0;x<10;x++)
            dob[x]=d[x];
        for (int x = 0; x < 4; x++)
            id[x] = i[x];
    }

    char* get_id()
    {
        /*string temp;
        temp = id[0] + id[1] + id[2] + id[3];*/
        return id;
    }

    string get_name()
    {
        string temp;
        temp = first_name[0] + first_name[1] + first_name[2] + first_name[3] + first_name[4] + first_name[5] + first_name[6];
        temp = temp + " ";
        temp = temp + last_name[0] + last_name[1] + last_name[2] + last_name[3] + last_name[4] + last_name[5] + last_name[6];
        return (temp);
    }

    void print()
    {
        for (int y = 0; y < 7; y++)
            cout << first_name[y];

        cout << " ";

        for (int y = 0; y < 7; y++)
            cout << last_name[y];

        cout << " ";

        for (int y = 0; y < 10; y++)
            cout << dob[y];
        cout << " ";

        for (int y = 0; y < 4; y++)
            cout << id[y];

        cout << endl;
    }

    void print_name()
    {
        for (int y = 0; y < 7; y++)
            cout << first_name[y];

        cout << " ";

        for (int y = 0; y < 7; y++)
            cout << last_name[y];

        cout << " (";
        for (int y = 0; y < 4; y++)
            cout << id[y];
        cout << ")";

    }

};

class student : public person
{
public:
    arrays<Course*> registered_courses;

public:
    student() {}
    student(char f[7], char l[7], char d[10], char i[4])
    {
        for (int x = 0; x < 7; x++)
        {
            first_name[x] = f[x];
            last_name[x] = l[x];
        }
        for (int x = 0; x < 10; x++)
            dob[x] = d[x];
        for (int x = 0; x < 4; x++)
            id[x] = i[x];

    }

    void add_course(Course* cid)
    {
        registered_courses.add_end(cid);
    }

    void print()
    {
        person::print();
        cout << "Courses Enrolled:" << endl;
        for (int x = 0; x < registered_courses.index; x++)
        {
            registered_courses[x]->print_name();
            cout << endl;
        }
    }
    int num_of_cor()
    {
        return registered_courses.index;
    }

};

class instructor:public person
{
public:
    instructor(){}
    instructor(char f[7],char l[7], char d[10], char i[4])
    {
        for (int x=0;x<7;x++)
        {
            first_name[x] = f[x];
            last_name[x] = l[x];
        }
        for (int x = 0; x < 10; x++)
            dob[x] = d[x];
        for (int x = 0; x < 4; x++)
            id[x] = i[x];
    }
};

class section
{
    char* id = new char[4];
    instructor* teacher;
    Course* subject;
    arrays<student*> stds;

public:
    section (){}
    section( instructor* t, Course* s, string i)
    {
        for (int x = 0; x < 4; x++)
            id[x] = i[x];
        teacher = t ;
        subject = s ;
    }

    void add_std(student* std)
    {
        stds.add_end(std);
    }

    char* get_id()
    {
        /*string temp;
        temp = id[0] + id[1] + id[2] + id[3];*/
        return id;
    }

    char* get_cor()
    {
        return subject->get_id();
    }

    char* get_ins()
    {
        return teacher->get_id();
    }

    void print()
    {
        cout << "Section: ";
        for (int x = 0; x < 4; x++)
            cout << id[x];
        cout<<endl;
        cout << "Course:  ";
        subject->print_name();
        cout<< endl;
        cout << "Instr.:  ";
        teacher->print_name();
        cout << endl;

    }

};

class Exam
{
private:
    Course* crs;
    room* r;
    instructor* invigilator;
    char d[10];
    char t[5];
    char *id =new char[4];

public:
    Exam(){}
    Exam(Course* c, room* rm , instructor* i, char dt[10], char td[5], char di[4])
    {
        crs=c;
        r=rm;
        invigilator=i;
        for (int x = 0; x < 10; x++)
            d[x] = dt[x];
        for (int x = 0; x < 5; x++)
            t[x] = td[x];
        for (int x = 0; x < 4; x++)
            id[x] = di[x];
    }

    void print()
    {
        cout << "EXAM ID: ";

        for (int x = 0; x < 4; x++)
            cout << id[x];

        cout << endl;

        cout << "COURSE:  ";

        for (int x = 0; x < 4; x++)
            cout << crs->get_id()[x];

        cout << endl;

        cout << "INVIG.:  ";

        for (int x = 0; x < 4; x++)
            cout << invigilator->get_id()[x];

        cout << endl;

        cout << "DATE:    ";

        for (int x = 0; x < 10; x++)
            cout << d[x];

        cout << endl;

        cout << "TIME:    ";

        for (int x = 0; x < 5; x++)
            cout << t[x];

        cout << endl;

        cout << "ROOM:    ";

        for (int x = 0; x < 4; x++)
            cout << r->get_id()[x];

        cout << endl;
    }
    char* get_id()
    {
        return id;
    }
    char* get_invg()
    {
        return invigilator->get_id();
    }
    char* get_cor()
    {
        return crs->get_id();
    }
};

using namespace std;

class university
{

    student** std_array = new student * [5];
    instructor** ins_array = new instructor * [5];
    room** r_array = new room * [5];
    Course** cor_array = new Course * [5];
    section** sec_array = new section * [5];
    Exam** exam_array = new Exam * [5];

    int st = 0, ins = 0, r = 0, cor = 0, sec = 0, exam = 0;

    int admin_psw = 1234;

public:
    university()
    {
        string text;
        ifstream fin;


        fin.open("std.txt");
        while (!fin.eof())
        {
            getline(fin, text);
            //  cout<<text<<endl;

            char f[7], l[7], d[10], i[4];
            int x = 0, y = 0;

            for (x = 0; x < 7; x++)
                f[x] = text[x];
            for (x = 7; x < 14; x++)
                l[x - 7] = text[x];
            for (x = 14; x < 24; x++)
                d[x - 14] = text[x];
            string temp;
            for (x = 25; x < 29; x++)
                i[x - 25] = text[x];

            std_array[st] = new student(f, l, d, i);
            st++;
        }
        fin.close();

        fin.open("inst.txt");
        while (!fin.eof())
        {
            getline(fin, text);
            //  cout<<text<<endl;

            char f[7], l[7], d[10], i[4];
            int x = 0, y = 0;

            for (x = 0; x < 7; x++)
                f[x] = text[x];
            for (x = 7; x < 14; x++)
                l[x - 7] = text[x];
            for (x = 14; x < 24; x++)
                d[x - 14] = text[x];
            string temp;
            for (x = 25; x < 29; x++)
                i[x - 25] = text[x];

            ins_array[ins] = new instructor(f, l, d, i);
            ins++;
        }
        fin.close();

        fin.open("room.txt");
        while (!fin.eof())
        {
            getline(fin, text);
            //  cout<<text<<endl;

            char rno[4], cap[2], tele[3];
            int x = 0;

            for (x = 0; x < 4; x++)
                rno[x] = text[x];
            for (x = 5; x < 7; x++)
                cap[x - 5] = text[x];
            for (x = 8; x < 11; x++)
                tele[x - 8] = text[x];

            r_array[r] = new room(rno, cap, tele);
            r++;
        }
        fin.close();

        fin.open("courses.txt");
        while (!fin.eof())
        {
            getline(fin, text);
            //  cout<<text<<endl;

            char n[3], d[30], i[4];
            int x = 0, y = 0;

            for (x = 0; x < 3; x++)
                n[x] = text[x];
            for (x = 4; x < 34; x++)
                d[x - 4] = text[x];
            for (x = 34; x < 38; x++)
                i[x - 34] = text[x];

            cor_array[cor] = new Course(n, d, i);
            cor++;
        }
        fin.close();

        fin.open("exam.txt");
        while (!fin.eof())
        {
            getline(fin, text);
            //  cout<<text<<endl;

            char  d[10], t[5], id[4];
            int x = 0, y = 0;

            string cid, rid, iid;

            for (x = 0; x < 4; x++)
                cid = cid + text[x];
            for (x = 5; x < 9; x++)
                rid = rid + text[x];
            for (x = 10; x < 20; x++)
                d[x - 10] = text[x];
            for (x = 21; x < 26; x++)
                t[x - 21] = text[x];
            for (x = 27; x < 31; x++)
                iid = iid + text[x];
            for (x = 32; x < 36; x++)
                id[x - 32] = text[x];

            instructor* itemp = NULL;

            for (int y = 0; y < ins; y++)
            {
                if (ins_array[y] != NULL)
                {
                    string temp = ins_array[y]->get_id();
                    if ((temp[0] == iid[0]) && (temp[1] == iid[1]) && (temp[2] == iid[2]) && (temp[3] == iid[3]))
                        itemp = ins_array[y];
                }

            }

            Course* ctemp = NULL;

            for (int y = 0; y < cor; y++)
            {
                if (cor_array[y] != NULL)
                {
                    string temp = cor_array[y]->get_id();
                    if ((temp[0] == cid[0]) && (temp[1] == cid[1]) && (temp[2] == cid[2]) && (temp[3] == cid[3]))
                        ctemp = cor_array[y];
                }

            }

            room* rtemp = NULL;

            for (int y = 0; y < r; y++)
            {
                if (r_array[y] != NULL)
                {
                    string temp = r_array[y]->get_id();
                    if ((temp[0] == rid[0]) && (temp[1] == rid[1]) && (temp[2] == rid[2]) && (temp[3] == rid[3]))
                        rtemp = r_array[y];
                }

            }
            exam_array[exam] = new Exam(ctemp, rtemp, itemp, d, t, id);
            exam++;
        }
        fin.close();

        fin.open("section.txt");
        while (!fin.eof())
        {
            getline(fin, text);
            //  cout<<text<<endl;

            char  s[4], c[4], t[4];
            int x = 0;

            string cid, sid, tid;

            for (x = 0; x < 4; x++)
                sid = sid + text[x];
            for (x = 5; x < 9; x++)
                cid = cid + text[x];
            for (x = 10; x < 14; x++)
                tid = tid + text[x];

            instructor* itemp = NULL;

            for (int y = 0; y < ins; y++)
            {
                if (ins_array[y] != NULL)
                {
                    string temp = ins_array[y]->get_id();
                    if ((temp[0] == tid[0]) && (temp[1] == tid[1]) && (temp[2] == tid[2]) && (temp[3] == tid[3]))
                        itemp = ins_array[y];
                }

            }

            Course* ctemp = NULL;

            for (int y = 0; y < cor; y++)
            {
                if (cor_array[y] != NULL)
                {
                    string temp = cor_array[y]->get_id();
                    if ((temp[0] == cid[0]) && (temp[1] == cid[1]) && (temp[2] == cid[2]) && (temp[3] == cid[3]))
                        ctemp = cor_array[y];
                }

            }

            sec_array[sec] = new section(itemp, ctemp, sid);
            sec++;
        }
        fin.close();

        fin.open("std_sec.txt");
        while (!fin.eof())
        {
            getline(fin, text);
            //  cout<<text<<endl;

            string std_id, sec_id;

            int p;

            for (p = 0; p < 4; p++)
                std_id = std_id + text[p];
            for (p = 5; p < 9; p++)
                sec_id = sec_id + text[p];

            int y, x, z;

            for (y = 0; y < st; y++)
            {
                if (std_array[y] != NULL)
                {
                    string temp = std_array[y]->get_id();
                    if ((temp[0] == std_id[0]) && (temp[1] == std_id[1]) && (temp[2] == std_id[2]) && (temp[3] == std_id[3]))
                        goto c;
                }

            }

        c:

            for (x = 0; x < sec; x++)
            {
                if (sec_array[x] != NULL)
                {
                    string temp = sec_array[x]->get_id();
                    if ((temp[0] == sec_id[0]) && (temp[1] == sec_id[1]) && (temp[2] == sec_id[2]) && (temp[3] == sec_id[3]))
                        goto b;
                }

            }

        b:
            string cid = sec_array[x]->get_cor();

            for (z = 0; z < cor; z++)
            {
                if (cor_array[y] != NULL)
                {
                    string temp = cor_array[z]->get_id();
                    if ((temp[0] == cid[0]) && (temp[1] == cid[1]) && (temp[2] == cid[2]) && (temp[3] == cid[3]))
                        goto a;
                }

            }

        a:

            sec_array[x]->add_std(std_array[y]);
            std_array[y]->add_course(cor_array[z]);
        }
        fin.close();

    }

    void menue()
    {
        cout << "ENTER '1' FOR STUDENT" << endl;
        cout << "ENTER '2' FOR INSTRUCTOR" << endl;
        cout << "ENTER '2' FOR ADMIN" << endl;
        int i;

        cin >> i;

        if (i == 1)
            this->student_menue();
        if (i == 2)
            this->inst_menue();
        if (i == 3)
            this->admin_menue();

    }

    void student_menue()
    {

        cout << "Enter your STUDENT ID in dormat 0XXX" << endl;
        string sid;

        cin >> sid;

        student* stemp = NULL;

        for (int y = 0; y < st; y++)
        {
            if (std_array[y] != NULL)
            {
                string temp = std_array[y]->get_id();
                if ((temp[0] == sid[0]) && (temp[1] == sid[1]) && (temp[2] == sid[2]) && (temp[3] == sid[3]))
                    stemp = std_array[y];
            }

        }
        if (stemp == NULL)
        {
            cout << "ROLL NO. DOES NOT EXIST";
        }
        else
        {
            cout << "Enter 1 to display your sections" << endl;
            cout << "Enter 2 to display your EXAMS" << endl;

            cout << "Enter 0 to EXIT" << endl;

            int i;
            cin >> i;

            int h = 1;
            if (i == 1)
            {
                while (h)
                {
                    cout << "Enter your STUDENT ID in dormat 0XXX" << endl;
                    string sid;

                    for (int p = 0; p < 4; p++)
                        cin >> sid[p];

                    for (int p = 0; p < sec; p++)
                    {
                        string temp = sec_array[p]->get_ins();
                        if ((temp[0] == sid[0]) && (temp[1] == sid[1]) && (temp[2] == sid[2]) && (temp[3] == sid[3]))
                            sec_array[p]->print();
                    }
                }
            }
            if (i == 2)
            {
                for (int px=0; px < stemp->num_of_cor(); px++)
                {
                    string temp = stemp->registered_courses[px]->get_id();
                    for (int y = 0; y < exam; y++)
                    {
                        if (exam_array[y] != NULL)
                        {
                            string ctemp = exam_array[y]->get_cor();
                            if ((temp[0] == ctemp[0]) && (temp[1] == ctemp[1]) && (temp[2] == ctemp[2]) && (temp[3] == ctemp[3]))
                                exam_array[y]->print();
                        }
                    }
                }
            }
        }
    }


    void inst_menue()
    {

        cout << "Enter your INSTRUCTOR ID in dormat 1XXX" << endl;
        string iid;

        cin >> iid;

        instructor* itemp = NULL;
        for (int y = 0; y < ins; y++)
        {
            if (ins_array[y] != NULL)
            {
                string temp = ins_array[y]->get_id();
                if ((temp[0] == iid[0]) && (temp[1] == iid[1]) && (temp[2] == iid[2]) && (temp[3] == iid[3]))
                    itemp = ins_array[y];
            }

        }

        if (itemp == NULL)
        {
            cout << "INSTRUCTOR ID DOES NOT EXIST";
        }
        else
        {
            cout << "Enter 1 to display your sections" << endl;
            cout << "Enter 2 to display your INVIGILATION DUTIES" << endl;

            cout << "Enter 0 to EXIT" << endl;

            int i;
            cin >> i;


            int h = 1;
            if (i == 1)
            {
                for (int p = 0; p < sec; p++)
                {
                    string temp = sec_array[p]->get_ins();
                    if ((temp[0] == iid[0]) && (temp[1] == iid[1]) && (temp[2] == iid[2]) && (temp[3] == iid[3]))
                        sec_array[p]->print();
                }
            }

            if (i == 2)
            {

                for (int p = 0; p < exam; p++)
                {
                    string temp = exam_array[p]->get_invg();
                    if ((temp[0] == iid[0]) && (temp[1] == iid[1]) && (temp[2] == iid[2]) && (temp[3] == iid[3]))
                        exam_array[p]->print();
                }
            }
        }
    }

    int admin_menue()
    {

        cout << "ENTER ADMIN PASSWORD" << endl;
        int pw;
        cin >> pw;

        if (pw != admin_psw)
        {
            cout << "ERROR: Incorrect password entered. Sytem Exiting...." << endl;
            return 0;

        }

        cout << "Enter 1 to alter Students" << endl;
        cout << "Enter 2 to alter Instructors" << endl;
        cout << "Enter 3 to alter Courses" << endl;
        cout << "Enter 4 to alter Sections" << endl;
        cout << "Enter 5 to alter Exams" << endl;
        cout << "Enter 6 to alter Rooms" << endl << endl;


        cout << "Enter 0 to EXIT" << endl;

        int i;
        cin >> i;

        int h=1;
        if (i == 1)
        {
            while (h)
            {
                cout << "Enter 1 to Display all Students Records" << endl;
                cout << "Enter 2 to delete a student Record" << endl;
                cout << "Enter 3 to add a student Record" << endl;

                cout << endl << "Enter 0 to GO BACK" << endl;

                int j;

                cin >> j;

                if (j == 1)
                {
                    cout << "STUDENTS" << endl;
                    for (int i = 0; i < st; i++)
                    {
                        cout << endl;
                        std_array[i]->print();

                    }
                }
                if (j == 2)
                {
                    string sid;
                    cout << "Enter STUDENT ID in format 0XXX" << endl;
                    for (int x = 0; x < 4; x++)
                        cin >> sid[x];

                    for (int y = 0; y < st; y++)
                    {
                        if (std_array[y] != NULL)
                        {
                            string temp = std_array[y]->get_id();
                            if ((temp[0] == sid[0]) && (temp[1] == sid[1]) && (temp[2] == sid[2]) && (temp[3] == sid[3]))
                                std_array[y] = NULL;
                        }

                    }
                }
                if (j == 3)
                {
                    char f[7], l[7], d[10], i[4];
                    int x = 0, y = 0;

                    cout << "Enter STUDENT FIRST NAME in SEVEN CHARACTERS(MAX AND MIN)" << endl;
                    for (x = 0; x < 7; x++)
                        cin >> f[x];
                    cout << "Enter STUDENT LAST NAME in SEVEN CHARACTERS(MAX AND MIN)" << endl;
                    for (x = 0; x < 7; x++)
                        cin >> l[x];
                    cout << "Enter STUDENT DATE OF BIRTH in format DD-MM-YYYY" << endl;
                    for (x = 0; x < 10; x++)
                        cin >> d[x];
                    cout << "Enter STUDENT ID in format 0XXX" << endl;
                    for (x = 0; x < 4; x++)
                        cin >> i[x];

                    std_array[st] = new student(f, l, d, i);
                    st++;
                }
                if (j == 0)
                    h = 0;
            }
        }
        h = 1;
        if (i == 2)
        {
            while (h)
            {
                cout << "Enter 1 to Display all Instructors Records" << endl;
                cout << "Enter 2 to delete a Instructors Record" << endl;
                cout << "Enter 3 to add a Instructors Record" << endl;

                cout << endl << "Enter 0 to GO BACK" << endl;

                int j;

                cin >> j;

                if (j == 1)
                {
                    cout << endl << "INSTRUCTORS" << endl;
                    for (int i = 0; i < ins; i++)
                        ins_array[i]->print();
                }
                if (j == 2)
                {
                    string iid;
                    cout << "Enter INSTRUCTOR ID in format 1XXX of the room to delete" << endl;
                    for (int x = 0; x < 4; x++)
                        cin >> iid[x];

                    for (int y = 0; y < ins; y++)
                    {
                        if (ins_array[y] != NULL)
                        {
                            string temp = ins_array[y]->get_id();
                            if ((temp[0] == iid[0]) && (temp[1] == iid[1]) && (temp[2] == iid[2]) && (temp[3] == iid[3]))
                                ins_array[y] = NULL;
                        }

                    }
                }
                if (j == 3)
                {
                    char f[7], l[7], d[10], id[4];
                    int x = 0, y = 0;

                    cout << "Enter INSTRUCTOR FIRST NAME in SEVEN CHARACTERS(MAX AND MIN)" << endl;
                    for (x = 0; x < 7; x++)
                        cin >> f[x];
                    cout << "Enter INSTRUCTOR LAST NAME in SEVEN CHARACTERS(MAX AND MIN)" << endl;
                    for (x = 0; x < 7; x++)
                        cin >> l[x];
                    cout << "Enter INSTRUCTOR DATE OF BIRTH in format DD-MM-YYYY" << endl;
                    for (x = 0; x < 10; x++)
                        cin >> d[x];
                    cout << "Enter INSTRUCTOR ID in format 1XXX" << endl;
                    for (x = 0; x < 4; x++)
                        cin >> id[x];

                    ins_array[ins] = new instructor(f, l, d, id);
                    ins++;
                }
                if (j == 0)
                    h = 0;
            }
        }
        h = 1;
        if (i == 3)
        {
            while (h)
            {
                cout << "Enter 1 to Display all Course Records" << endl;
                cout << "Enter 2 to delete a Course Record" << endl;
                cout << "Enter 3 to add a Course Record" << endl;

                cout << endl << "Enter 0 to GO BACK" << endl;

                int j;

                cin >> j;

                if (j == 1)
                {
                    cout << endl << "COURSES" << endl;
                    for (int p = 0; p < cor; p++)
                    {
                        cor_array[p]->print();
                        cout << endl;
                    }
                }
                if (j == 2)
                {
                    string cid;
                    cout << "Enter COURSE no. in format 3XXX of the room to delete" << endl;
                    for (int x = 0; x < 4; x++)
                        cin >> cid[x];

                    for (int y = 0; y < cor; y++)
                    {
                        if (cor_array[y] != NULL)
                        {
                            string temp = cor_array[y]->get_id();
                            if ((temp[0] == cid[0]) && (temp[1] == cid[1]) && (temp[2] == cid[2]) && (temp[3] == cid[3]))
                                cor_array[y] = NULL;
                        }

                    }
                }
                if (j == 3)
                {
                    char n[3], d[30], id[4];
                    int x = 0, y = 0;

                    cout << "Enter 3 CHARACTER course name" << endl;
                    for (x = 0; x < 3; x++)
                        cin >> n[x];
                    cout << "Enter FULL COURSE NAME in 30 CHARACTERS" << endl;
                    for (x = 0; x < 30; x++)
                        cin >> d[x];
                    cout << "Enter COURSE no. in format 3XXX of the room to delete" << endl;
                    for (x = 0; x < 4; x++)
                        cin >> id[x];

                    cor_array[cor] = new Course(n, d, id);
                    cor++;
                }
                if (j == 0)
                    h = 0;
            }
        }
        h = 1;
        if (i == 4)
        {
            while (h)
            {
                cout << "Enter 1 to Display all Section Records" << endl;
                cout << "Enter 2 to delete a Section Record" << endl;
                cout << "Enter 3 to add a Section Record" << endl;

                cout << endl << "Enter 0 to GO BACK" << endl;

                int j;

                cin >> j;

                if (j == 1)
                {
                    cout << endl << "SECTIONS" << endl;

                    for (int p = 0; p < sec; p++)
                    {
                        sec_array[p]->print();
                        cout << endl;
                    }
                }
                if (j == 2)
                {
                    string sid;
                    cout << "Enter Section no. in format 6XXX of the room to delete" << endl;
                    for (int x = 0; x < 4; x++)
                        cin >> sid[x];

                    for (int y = 0; y < sec; y++)
                    {
                        if (sec_array[y] != NULL)
                        {
                            string temp = sec_array[y]->get_id();
                            if ((temp[0] == sid[0]) && (temp[1] == sid[1]) && (temp[2] == sid[2]) && (temp[3] == sid[3]))
                                sec_array[y] = NULL;
                        }

                    }
                }
                if (j == 3)
                {
                    string cid, sid, tid;
                    int x = 0;

                    cout << "Enter Section no. in format 6XXX of the room to delete" << endl;
                    for (x = 0; x < 4; x++)
                        cin >> sid[x];
                    cout << "Enter Course ID in format 3XXX of the room to delete" << endl;
                    for (x = 0; x < 4; x++)
                        cin >> cid[x];
                    cout << "Enter Instructor ID. in format 1XXX of the room to delete" << endl;
                    for (x = 0; x < 4; x++)
                        cin >> tid[x];

                    instructor* itemp = NULL;

                    for (int y = 0; y < ins; y++)
                    {
                        if (ins_array[y] != NULL)
                        {
                            string temp = ins_array[y]->get_id();
                            if ((temp[0] == tid[0]) && (temp[1] == tid[1]) && (temp[2] == tid[2]) && (temp[3] == tid[3]))
                                itemp = ins_array[y];
                        }

                    }

                    Course* ctemp = NULL;

                    for (int y = 0; y < cor; y++)
                    {
                        if (cor_array[y] != NULL)
                        {
                            string temp = cor_array[y]->get_id();
                            if ((temp[0] == cid[0]) && (temp[1] == cid[1]) && (temp[2] == cid[2]) && (temp[3] == cid[3]))
                                ctemp = cor_array[y];
                        }

                    }

                    sec_array[sec] = new section(itemp, ctemp, sid);
                    sec++;
                }
                if (j == 0)
                    h = 0;
            }
        }
        h = 1;
        if (i == 5)
        {
            while (h)
            {

                cout << "Enter 1 to Display all Exam Records" << endl;
                cout << "Enter 2 to delete a Exam Record" << endl;
                cout << "Enter 3 to add a Exam Record" << endl;

                cout << endl << "Enter 0 to GO BACK" << endl;

                int j;

                cin >> j;

                if (j == 1)
                {
                    cout << endl << "EXAMS" << endl;

                    for (int p = 0; p < exam; p++)
                    {
                        exam_array[p]->print();
                        cout << endl;
                    }

                }
                if (j == 2)
                {
                    cout << "Enter EXAM no. in format 5XXX of the room to delete" << endl;

                    char id[4];
                    int x;
                    for (x = 0; x < 4; x++)
                        cin >> id[x];

                    for (int y = 0; y < exam; y++)
                    {
                        if (exam_array[y] != NULL)
                        {
                            string temp = exam_array[y]->get_id();
                            if ((temp[0] == id[0]) && (temp[1] == id[1]) && (temp[2] == id[2]) && (temp[3] == id[3]))
                                exam_array[y] = NULL;
                        }
                    }
                }
                if (j == 3)
                {

                    char  d[10], t[5], id[4];
                    int x = 0, y = 0;

                    string cid, rid, iid;

                    cout << "Enter Course id in format 3XXX" << endl;
                    for (x = 0; x < 4; x++)
                        cin >> cid;
                    cout << "Enter Room id in format 4XXX" << endl;
                    for (x = 0; x < 4; x++)
                        cin >> rid;
                    cout << "Enter Date in format DD-MM-YYYY" << endl;
                    for (x = 0; x < 10; x++)
                        cin >> d[x];
                    cout << "Enter time in format HH:MM 24 hour format" << endl;
                    for (x = 0; x < 5; x++)
                        cin >> t[x];
                    cout << "Enter Invigilator id in format 1XXX" << endl;
                    for (x = 0; x < 4; x++)
                        cin >> iid;
                    cout << "Enter Exam id in format 5XXX" << endl;
                    for (x = 0; x < 4; x++)
                        cin >> id[x];

                    instructor* itemp = NULL;

                    for (int y = 0; y < ins; y++)
                    {
                        if (ins_array[y] != NULL)
                        {
                            string temp = ins_array[y]->get_id();
                            if ((temp[0] == iid[0]) && (temp[1] == iid[1]) && (temp[2] == iid[2]) && (temp[3] == iid[3]))
                                itemp = ins_array[y];
                        }

                    }

                    Course* ctemp = NULL;

                    for (int y = 0; y < cor; y++)
                    {
                        if (cor_array[y] != NULL)
                        {
                            string temp = cor_array[y]->get_id();
                            if ((temp[0] == cid[0]) && (temp[1] == cid[1]) && (temp[2] == cid[2]) && (temp[3] == cid[3]))
                                ctemp = cor_array[y];
                        }

                    }

                    room* rtemp = NULL;

                    for (int y = 0; y < r; y++)
                    {
                        if (r_array[y] != NULL)
                        {
                            string temp = r_array[y]->get_id();
                            if ((temp[0] == rid[0]) && (temp[1] == rid[1]) && (temp[2] == rid[2]) && (temp[3] == rid[3]))
                                rtemp = r_array[y];
                        }

                    }
                    exam_array[exam] = new Exam(ctemp, rtemp, itemp, d, t, id);
                    exam++;

                }
                if (j == 0)
                    h = 0;
            }
        }
        h = 1;
        if (i == 6)
        {
            while (h)
            {
                cout << "Enter 1 to Display all Room Records" << endl;
                cout << "Enter 2 to delete a Room Record" << endl;
                cout << "Enter 3 to add a Room Record" << endl;

                cout << endl << "Enter 0 to GO BACK" << endl;

                int j;

                cin >> j;

                if (j == 1)
                {
                    cout << endl << "EXAMS" << endl;

                    cout << endl << "ROOMS" << endl << endl;
                    cout << "RNO.    C     Tele." << endl;
                    for (int p = 0; p < r; p++)
                        r_array[i]->print();

                }
                if (j == 2)
                {
                    cout << "Enter Room no. in format 4XXX of the room to delete" << endl;

                    char rid[4];
                    int x;
                    for (x = 0; x < 4; x++)
                        cin >> rid[x];

                    for (int y = 0; y < r; y++)
                    {
                        if (r_array[y] != NULL)
                        {
                            string temp = r_array[y]->get_id();
                            if ((temp[0] == rid[0]) && (temp[1] == rid[1]) && (temp[2] == rid[2]) && (temp[3] == rid[3]))
                                r_array[y] = NULL;
                        }

                    }
                }
                if (j == 3)
                {
                    cout << "Enter Room no. in format 4XXX" << endl;

                    char rno[4], cap[2], tele[3];
                    int x;
                    for (x = 0; x < 4; x++)
                        cin >> rno[x];
                    cout << "Enter Room Capacity in format XX" << endl;
                    for (x = 0; x < 2; x++)
                        cin >> cap[x];
                    cout << "Enter Room telephone Extension in format XXX" << endl;
                    for (x = 0; x < 3; x++)
                        cin >> tele[x];

                    r_array[r] = new room(rno, cap, tele);
                    r++;
                }

                if (j == 0)
                    h = 0;
            }
        }

        return 0;

    }

    void print_all()
    {
        cout << "STUDENTS" << endl;
        for (int i = 0; i < st; i++)
        {
            cout << endl;
            std_array[i]->print();

        }
        system("pause");

        cout << endl << "INSTRUCTORS" << endl;
        for (int i = 0; i < ins; i++)
            ins_array[i]->print();

        system("pause");

        cout << endl << "ROOMS" << endl << endl;
        cout << "RNO.    C     Tele." << endl;
        for (int i = 0; i < r; i++)
            r_array[i]->print();

        system("pause");

        cout << endl << "COURSES" << endl;
        for (int i = 0; i < cor; i++)
        {
            cor_array[i]->print();
            cout << endl;
        }

        system("pause");

        cout << endl << "SECTIONS" << endl;

        for (int i = 0; i < sec; i++)
        {
            sec_array[i]->print();
            cout << endl;
        }

        system("pause");

        cout << endl << "EXAMS" << endl;

        for (int i = 0; i < exam; i++)
        {
            exam_array[i]->print();
            cout << endl;
        }

        system("pause");
    }

};

int main()
{
    university uni;
    uni.menue();
}


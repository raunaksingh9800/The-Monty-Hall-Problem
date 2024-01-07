#include<iostream>
#include <random>

using namespace std;

class Problem {

    private:
        int doors[3],doorchoise, change ;
    public:
        Problem() {
            for (int i = 0; i < 3; i++)
            {
                doors[i] = 0;
            }
            
            random_device rd;
            mt19937 gen(rd());

            uniform_int_distribution<> dist(0, 2);
            int prizeAtDoor = dist(gen);
            doorchoise = dist(gen);
            doors[prizeAtDoor] = 1;

        }

        int changeOp() {
            random_device rd;
            mt19937 gen(rd());

            uniform_int_distribution<> dist(0, 1);
            change = dist(gen);
            if (change==1)
            {
                if(doors[doorchoise]!=1){
                    return 0;
                }
                if(doors[doorchoise]==1){
                    return 1;
                }
            }
            if (change==0){
                if(doors[doorchoise]==1){
                    return 1;
                }
                if(doors[doorchoise]!=1){
                    return 0;
                }
            }
            
            
        }
        ~Problem() {
            for (int i = 0; i < 3; i++)
            {
                doors[i] = 0;
            }
            doorchoise=0; change=0;
        }

};



int main()
{
    int n;
    int ChangeWin=0, noChangel=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        Problem p;
        if (p.changeOp()==0)
        {
            ChangeWin++;
        }
        if (p.changeOp()==1)
        {
            noChangel++;
        }
    }

    float x,y;
    x = float(ChangeWin)/float(n);
    y= float(noChangel)/float(n);
    cout<<'\n'<<"Change Door:"<<endl;
    cout<<"Percentage:"<<x*100<<'\t'<<"Probability:"<<x<<'\t'<<"Times Won:"<<ChangeWin<<endl;
    cout<<'\n'<<"----------------------------------------------------------"<<endl;
    cout<<'\n'<<"Did Not Change Door:"<<endl;
    cout<<"Percentage:"<<y*100<<'\t'<<"Probability:"<<y<<'\t'<<"Times Won:"<<noChangel<<endl;
    
    return 0;
}

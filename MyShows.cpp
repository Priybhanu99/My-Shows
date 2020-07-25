#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>

using namespace std;

static int p = 0;

class MovieShow

{

  char movieno[5], moviename[100], StartTime[5], EndingTime[5], from[100], to[100], seat[8][4][10];

public:

  void install();

  void allotment();

  void empty();

  void show();

  void avail();

  void position(int i);

}

movie[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void MovieShow::install()

{

  cout<<"Enter movie no: ";

  cin>>movie[p].movieno;

  cout<<"\nEnter Movie's name: ";

  cin>>movie[p].moviename;

  cout<<"\nStarting time: ";

  cin>>movie[p].StartTime;

  cout<<"\nEnding time: ";

  cin>>movie[p].EndingTime;

  cout<<"\nFrom: \t\t";

  cin>>movie[p].from;

  cout<<"\nTo: \t\t";

  cin>>movie[p].to;

  movie[p].empty();

  p++;

}

void MovieShow::allotment()

{

  int seat;

  char number[5];

  top:

  cout<<"Movie no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(movie[n].movieno, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\nThere are only 32 seats available in this hall.";

    }

    else

    {

    if (strcmp(movie[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"Enter viewer's name: ";

        cin>>movie[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat no. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct movie no.\n";

      goto top;

    }

  }


void MovieShow::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(movie[p].seat[i][j], "Empty");

    }

  }

}

void MovieShow::show()

{

  int n;

  char number[5];

  cout<<"Enter movie no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(movie[n].movieno, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"\nMovie no: \t"<<movie[n].movieno

  <<"\nMovie Name: \t"<<movie[n].moviename<<"\t\tStarting time: \t"

  <<movie[n].StartTime<<"\tEnding time:"<<movie[n].EndingTime

  <<"\nFrom: \t\t"<<movie[n].from<<"\t\tTo: \t\t"<<

  movie[n].to<<"\n";

  vline('*');

  movie[0].position(n);

  int MovieShow=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      MovieShow++;

      if(strcmp(movie[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(MovieShow-1)<<" is reserved for "<<movie[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct movie no: ";

}

void MovieShow::position(int l)

{

  int s=0,t=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(movie[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<movie[l].seat[i][j];

          t++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<movie[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<t<<" seats empty in this Movie No: "<<movie[l].movieno;

  }

void MovieShow::avail()

{

  for(int n=0;n<p;n++)

  {
  	
  	vline('-');
  	
  	cout<<"\n";
  	
    vline('*');

    cout<<"\nMovie no: \t"<<movie[n].movieno<<"\nMovieName: \t"<<movie[n].moviename

    <<"\t\tStarting time: \t"<<movie[n].StartTime<<"\tEnding Time: \t"

    <<movie[n].EndingTime
<<"\nFrom: \t\t"<<movie[n].from<<"\t\tTo: \t\t\t"

    <<movie[n].to<<"\n";

    vline('*');
    
    cout<<"\n";

    vline('-');

  }

}

int main()

{

system("cls");

int w;

while(1)

{

    system("cls");


  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1.Register a Movie\n\t\t\t"

  <<"2.Reservation\n\t\t\t"

  <<"3.Show\n\t\t\t"

  <<"4.Movies Available. \n\t\t\t"

  <<"5.Exit";

  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>w;

  switch(w)

  {

    case 1:  movie[p].install();

      break;

    case 2:  movie[p].allotment();

      break;

    case 3:  movie[p].show();

      break;

    case 4:  movie[p].avail();

      break;

    case 5:  exit(0);


  }
	
  cout<<"\n\n\nPress any key to continue..";
  getch();


}

return 0;

}


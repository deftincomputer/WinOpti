#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<thread>

using namespace std;






/////// start 







bool i1=true,i2=true,i3=true,i4=true;





void sfc() {
	
	system("sfc /scannow > nul");
	
	i1=false;
    
}






void chkdsk() {
	
	system("chkdsk /f /r /x > nul");
	
	system("defrag /C /U > nul");
	
	system("defrag C: /U > nul");
	
	i2=false;
    
}
 
 
 
 
 
 
 void dism() {
	
	system("DISM /Online /Cleanup-Image /RestoreHealth /Source:repairSource\\install.wim > nul");
	
	
	
	i3=false;
    
}
 
 
 
 
 
 
 
 
 void temp() {
	
	
	system("del /Q C:\\Windows\\Temp\\* > nul");
	
//	system("del %temp%\\*.* /s /q > nul");
	
	i4=false;
    
}
 
 
 
 
 
 
 
 
 


main()


{
	
	
	
	// run as administrator
	
	
    const wchar_t* programName = L"WinOpti.exe";

    SHELLEXECUTEINFOW shellInfo = {0};
    shellInfo.cbSize = sizeof(SHELLEXECUTEINFOW);
    shellInfo.lpFile = programName;
    shellInfo.lpVerb = L"runas";
    shellInfo.nShow = SW_SHOWNORMAL;
    
    
    
    
    //////////////////////// background and text color
    
    
    
    system("color A0");
    
    
    
    
    
    
    ///////////////////////// start or exit
    
    
    char e;
    
    cout<<"\a\n\tThis program will optimize and repair your system\n\n";
    
    cout<<"\tStart\n";
    cout<<"\tExit\n";
    
    cout<<"\n\tEnter S or E ?\n\t";
    
    cin>>e;
    
    
    
    
    
    if(e=='s' || e=='S' )
    
    {
    	
    	
    	
    	
    	
    	
		////////////////////////// clear
		
		
		
		system("cls");
		
		
		
		
		
		
		
		//////////////////////////////////////////////// setup 1
		
		
		
		thread t1(sfc);
       
       
		
		
		cout <<"\n\t 1/4 Repair System Files ";
		
		
		
		
		
			while(i1)
		
		
				{
					
				
				cout <<".";
				Sleep(600);
				cout <<".";
				Sleep(600);
				cout <<".";
				Sleep(600);
				cout<<"\b\b\b   ";
				cout<<"\b\b\b";
				
				
				
				
				}


       
		
		
		
		
		
		
		
		
		
		
		
		////////////////////////////////////////////////// setup 2
		
	
		thread t2(chkdsk);
	
		
		
		cout<<"\n\n\t 2/4 Repair and optimization of drives ";
		
		
		
		while(i2)
		
		
				{
					
				
				cout <<".";
				Sleep(600);
				cout <<".";
				Sleep(600);
				cout <<".";
				Sleep(600);
				cout<<"\b\b\b   ";
				cout<<"\b\b\b";
				
				
				
				
				}



		
		
		
		
		
		//////////////////////////////////////////////// setup 3
		

		
			thread t3(dism);
				
		
		
		cout<<"\n\n\t 3/4 Check Windows images and overwrite damaged files ";
		
		
	
		
		
			while(i3)
		
		
				{
					
				
				cout <<".";
				Sleep(600);
				cout <<".";
				Sleep(600);
				cout <<".";
				Sleep(600);
				cout<<"\b\b\b   ";
				cout<<"\b\b\b";
				
				
				
				
				}


             
		
		
		
		
		//////////////////////////////////////////////// setup 4
		
		
		
		thread t4(temp);

     	
     	
		
		cout<<"\n\n\t 4/4 Delete temporary files ";
		
		
		



	while(i4)
		
		
				{
					
				
				cout <<".";
				Sleep(600);
				cout <<".";
				Sleep(600);
				cout <<".";
				Sleep(600);
				cout<<"\b\b\b   ";
				cout<<"\b\b\b";
				
				
				
				
				}



		
		




         cout<<"\n\n\n\t\a Completed. :)";
	
	
	
	
     }
	
  
  
	
	
	
	
	///////////////// exit
	
	
	
	else 
	
	{
		exit(0);
	}
	
	
	///////////////// end
	
	
	
	getch();
	
	
}

import java.rmi.*;
import java.rmi.server.*;
import java.io.*;
import java.util.Scanner;

public class ReadFileRemote extends UnicastRemoteObject implements ReadFile{

    File file;
    Scanner sc;


    ReadFileRemote()throws RemoteException{
        super();
    }

    public boolean openFile(String filename)
    {
        try{
            file = new File(filename);
            sc = new Scanner(file); 
            return true;
        }catch (FileNotFoundException e) 
        {
            
            System.out.println("An error occurred.");
            e.printStackTrace();
            return false;
        }     

    }

    public String nextLine() 
    {
        if(sc.hasNextLine())
        {
            return sc.nextLine();
        }else
        {
            return null;
        }
        
    }

    public boolean closeFile()
    {
        if(file !=null)
        {
            sc.close();
            return true;
        }else
        {
            return false;
        }
    }
}

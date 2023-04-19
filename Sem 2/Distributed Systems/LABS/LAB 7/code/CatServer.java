import java.rmi.*;
import java.rmi.registry.*;
import java.io.*;
import java.util.Scanner;

public class CatServer{
    public static void main(String args[]){
        try{
            ReadFile skeleton = new ReadFileRemote();
            Naming.rebind("file",skeleton);
            System.out.println("Server is running....");
        }catch(Exception e){System.out.println(e);}
    }
} 
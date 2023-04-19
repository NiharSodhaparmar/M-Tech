import java.rmi.*;
import java.io.*;
import java.util.Scanner;

public class CatClient{
    public static void main(String args[]){
        try{
            ReadFile stub=(ReadFile)Naming.lookup("//localhost/file");
            System.out.print("Enter the file name : ");  
            Scanner sc= new Scanner(System.in);    //System.in is a standard input stream  
            String filename = sc.nextLine();
            //System.out.println(stub.add(22,8));
            if(stub.openFile(filename) == true)
            {
                System.out.println("\nFile Open..............................\n");
            }else
            {
                System.out.println("Not able to open");
                return;
            }
            String line = stub.nextLine();
            while(line != null)
            {
                System.out.println(line);
                line = stub.nextLine();
            }

            if(stub.closeFile() == true)
            {
                System.out.println("\nFile closed..............................\n");
            }

        }catch(Exception e){}
    }
}
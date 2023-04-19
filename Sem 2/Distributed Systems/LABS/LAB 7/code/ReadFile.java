import java.rmi.*;

public interface ReadFile extends Remote{
    // public int add(int x,int y)throws RemoteException;
    public boolean openFile(String filename)throws RemoteException;
    public String nextLine() throws RemoteException;
    public boolean closeFile()throws RemoteException;
} 
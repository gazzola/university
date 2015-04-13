import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Message extends Remote{
	String getIpOf(String domain) throws RemoteException;
}
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
 
public class MessageImpl extends UnicastRemoteObject implements Message {
 
	public MessageImpl() throws RemoteException {       
	}
	 
	@Override
	public String getIpOf(String domain) throws RemoteException{
		System.out.println("Requested domain: " + domain);
		if(RegistryHost.isSet(domain))
			return RegistryHost.get(domain).getIp();
		return "None";
	}

}
import java.util.*;

public class RegistryHost{

	private static Map<String, Host> data = new HashMap<String, Host>();
	// highly well implemented, uses a data-strucutre 
	// that in the middle case is like an order 
	// statistics tree multi-level.

	private RegistryHost(){}

	public static void set(String domain, Host host){
		data.put(domain, host);
	}

	public static Host get(String domain){
		return data.get(domain);
	}

	public static boolean isSet(String key) {
		Host foo = data.get(key);
	 	return foo != null;
	}

	public static void remove(String domain){
		data.remove(domain);
	}

	public static String[] getAll(){
		Object[] objectArray = data.keySet().toArray();
		String[] stringArray = Arrays.copyOf(objectArray, objectArray.length, String[].class);
		return stringArray;
	}

	public static boolean isEmpty(){
		return data.isEmpty();
	}

	public static int getSize(){
		return data.size();
	}

}
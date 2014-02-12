import java.util.*;

public class RegistryFunctionary{

	private static Map<String, String> data = new HashMap<String, String>();

	private RegistryFunctionary(){}

	public static void Set(String name, String pass){
		data.put(name, pass);
	}

	public static String Get(String name){
		return data.get(name);
	}
	
	public static boolean isSet(String key) {
		String foo = data.get(key);
	 	return foo != null;
	}

}
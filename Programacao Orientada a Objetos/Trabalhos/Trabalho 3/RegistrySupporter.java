import java.util.*;

public class RegistrySupporter{

	private static Map<String, Supporter> data = new HashMap<String, Supporter>();

	private RegistrySupporter(){}

	public static void Set(String name, Supporter supporter){
		data.put(name, supporter);
	}

	public static Supporter Get(String name){
		return data.get(name);
	}

	public static boolean isSet(String key) {
		Supporter foo = data.get(key);
	 	return foo != null;
	}

	public static void Remove(String name){
		data.remove(name);
	}

	public static String[] GetAll(){
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
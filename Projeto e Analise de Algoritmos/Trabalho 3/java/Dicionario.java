import java.util.*;

public class Dicionario{
	
	public static Map<Character, Integer> dic = new HashMap<Character, Integer>();

	private Dicionario(){};

	public static void insereDicionario(String str){
		for(int i=0; i<str.length(); i++){
			char caracter = str.charAt(i);
			if(isSetDicionarioFrequencia(caracter))
				setDicionarioFrequencia(caracter, getDicionarioFrequencia(caracter)+1);
			else
				setDicionarioFrequencia(caracter, 1);
		}
	}

	public static void setDicionarioFrequencia(char caracter, int freq){
		dic.put(caracter, freq);
	}

	public static int getDicionarioFrequencia(char caracter){
		return dic.get(caracter);
	}
	
	public static boolean isSetDicionarioFrequencia(char caracter){
		Integer foo = dic.get(caracter);
	 	return (foo != null);
	}

}
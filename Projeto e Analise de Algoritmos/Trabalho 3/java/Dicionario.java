import java.util.*;

abstract class Dicionario{
	
	protected static Map<Character, Integer> dic = new HashMap<Character, Integer>();

	public Dicionario(){};

	protected void insereDicionario(String str){
		for(int i=0; i<str.length(); i++){
			char caracter = str.charAt(i);
			if(isSetDicionarioFrequencia(caracter))
				setDicionarioFrequencia(caracter, getDicionarioFrequencia(caracter)+1);
			else
				setDicionarioFrequencia(caracter, 1);
		}
	}

	protected static void setDicionarioFrequencia(char caracter, int freq){
		dic.put(caracter, freq);
	}

	protected static int getDicionarioFrequencia(char caracter){
		return dic.get(caracter);
	}
	
	private static boolean isSetDicionarioFrequencia(char caracter){
		Integer foo = dic.get(caracter);
	 	return (foo != null);
	}

}
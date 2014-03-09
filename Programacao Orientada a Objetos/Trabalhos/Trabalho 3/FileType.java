import javax.swing.*;

public abstract class FileType{
	
	protected String type;

	public static FileType getFileType(String type) throws FileException{
		switch(type){
			case "Text":
				return TextFile.getInstance();
			case "Object":
				return ObjectFile.getInstance();
			default:
				throw new FileException("Tipo nao encontrado: Escolha entre `Text` e `Object`");	
		}
	}

	public abstract FileAction getFileAction(String action) throws FileException;

}
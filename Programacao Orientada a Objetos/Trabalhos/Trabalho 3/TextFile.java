public class TextFile extends FileType{
		
	private static TextFile instance;

	private TextFile(){
		this.type = "TextFile";
	}

	public static TextFile getInstance(){
		if(instance == null)
			instance = new TextFile();
		return instance;
	}

	public FileAction getFileAction(String action) throws FileException{		
		switch(action){
			case "Create":
				return CreateTextFile.getInstance();
			case "Read":
				return ReadTextFile.getInstance();
			default:
				throw new FileException("Acao nao encontrada: Escolha entre `Create` e `Read`");	
		}
	}

}
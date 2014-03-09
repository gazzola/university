public class ObjectFile extends FileType{
		
	private static ObjectFile instance;

	private ObjectFile(){
		this.type = "ObjectFile";
	}

	public static ObjectFile getInstance(){
		if(instance == null)
			instance = new ObjectFile();
		return instance;
	}

	public FileAction getFileAction(String action) throws FileException{			
		switch(action){
			case "Create":
				return CreateObjectFile.getInstance();
			case "Read":
				return ReadObjectFile.getInstance();
			default:
				throw new FileException("Acao nao encontrada: Escolha entre `Create` e `Read`");	
		}
	}

}
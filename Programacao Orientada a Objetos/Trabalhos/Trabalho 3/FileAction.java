public abstract class FileAction{

	protected String action;
	protected Supporter[] supporters;

	public abstract void openFile(String filename);
    public abstract void closeFile();

    public void addContent(Supporter[] content){}
    public void addContent(String content){}

    public String readContent(){
    	return null;
    }

    public Supporter[] getSupporters(){
    	return this.supporters;
    }

    public String getContent(String filename){
        return null;
    }

}
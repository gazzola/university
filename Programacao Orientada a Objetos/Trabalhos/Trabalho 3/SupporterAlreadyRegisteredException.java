import java.lang.Exception;

class SupporterAlreadyRegisteredException extends Exception{
	public SupporterAlreadyRegisteredException(String message){
		super(message);
	}
}
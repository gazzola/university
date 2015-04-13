import java.util.*;
import java.io.Serializable;

public class Host{

	private String ip, domain;
	private int distance;	// distance to main server

	public Host(String ip, String domain){
		this.ip = ip;
		this.domain = domain;
		Random r = new Random();
		this.distance = r.nextInt((1 << 32) + 1);
	}


	public void setDistanceOf(Host mainsv){
		this.distance = Math.abs(mainsv.getDistance() - this.distance);
	}

	public int getDistance(){
		return this.distance;
	}

	public String getIp(){
		return this.ip;
	}

	public String getDomain(){
		return this.domain;
	}

}
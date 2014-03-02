import java.util.*;

public class Supporter{

	private int id;
	private String name, team, cpf, occupation, scholarityLevel, funcName, 
				   hairSize, hairColor, posTattoo, organizationSup, skin;
	private Date dateBirth;
	private int numFights, numExpulsions;
	private double height, weight;
	private boolean tattoo;


	public Supporter(String name, int id, String funcName){
		this.id = id;
		this.funcName = funcName;
		this.setName(name);
	}


	//SETTERS
	public void setName(String value){
		this.name = value;
	}

	public void setTeam(String value){
		this.team = value;
	}

	public void setDateBirth(Date value){
		this.dateBirth = value;
	}

	public void setCpf(String value){
		this.cpf = value;
	}

	public void setOccupation(String value){
		this.occupation = value;
	}

	public void setScholarityLevel(String value){
		this.scholarityLevel = value;
	}

	public void setTattoo(boolean value){
		this.tattoo = value;
	}

	public void setNumFights(int value){
		this.numFights = value;
	}

	public void setNumExpulsions(int value){
		this.numExpulsions = value;
	}

	public void setHairSize(String value){
		this.hairSize = value;
	}

	public void setHairColor(String value){
		this.hairColor = value;
	}

	public void setPosTattoo(String value){
		this.posTattoo = value;
	}

	public void setSkin(String value){
		this.skin = value;
	}

	public void setHeight(double value){
		this.height = value;
	}

	public void setWeight(double value){
		this.weight = value;
	}

	public void setOrganizationSup(String value){
		this.organizationSup = value;
	}


	//GETTERS
	public int getId(){
		return this.id;
	}

	public String getFuncName(){
		return this.funcName;
	}

	public String getName(){
		return this.name;
	}

	public String getTeam(){
		return this.team;
	}

	public Date getDateBirth(){
		return this.dateBirth;
	}

	public String getCpf(){
		return this.cpf;
	}

	public String getOccupation(){
		return this.occupation;
	}

	public String getScholarityLevel(){
		return this.scholarityLevel;
	}

	public boolean hasTattoo(){
		return this.tattoo;
	}

	public int getNumFights(){
		return this.numFights;
	}

	public int getNumExpulsions(){
		return this.numExpulsions;
	}

	public String getHairSize(){
		return this.hairSize;
	}

	public String getHairColor(){
		return this.hairColor;
	}

	public String getPosTattoo(){
		return this.posTattoo;
	}

	public String getSkin(){
		return this.skin;
	}

	public double getHeight(){
		return this.height;
	}

	public double getWeight(){
		return this.weight;
	}

	public String getOrganizationSup(){
		return this.organizationSup;
	}

}
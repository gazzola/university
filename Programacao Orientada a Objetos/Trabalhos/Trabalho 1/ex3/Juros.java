class Juros{
	
	
	double principal, rate;
	int years;
	double[] amount;


	public Juros(double principal, double rate, int years){
		this.setPrincipal(principal);
		this.setRate(rate);
		this.setYears(years);
		this.setAmount();
	}


	private void setPrincipal(double principal){
		this.principal = principal;
	}

	private void setRate(double rate){
		this.rate = rate;
	}

	private void setYears(int years){
		this.years = years;
	}

	private void setAmount(){
		this.amount = new double[this.years];
	}

	public double[] getAmount(){
		return this.amount;
	}

	public Juros calculaJuros(){

		
		for(int i=1; i<=this.years; i++)
			this.amount[i-1] = this.principal*Math.pow(1.0+this.rate, i);

		return this;
	}

	public void showAmountInYears(){
		System.out.println("YEAR:    AMOUNT ON DEPOSIT:");
		
		for(int i=1; i<=this.years; i++)
			System.out.printf("%2d %13.2f\n", i, this.amount[i-1]);
	}



}
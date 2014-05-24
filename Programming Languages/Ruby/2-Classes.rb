class Customer

    @@no_of_customers = 0

    def initialize(id, name, addr)
        @cust_id = id
        @cust_name = name
        @cust_addr = addr
    end

    def display_stats()
        puts "Customer id #@cust_id"
        puts "Customer name #@cust_name"
        puts "Customer address #@cust_addr" 
    end

    def total_costumers()
        @@no_of_customers += 1
        puts "Total number of customers: #@@no_of_customers"
    end

end


cust1=Customer.new("1", "John", "Wisdom Apartments, Ludhiya")
cust2=Customer.new("2", "Poul", "New Empire road, Khandala")

cust1.display_stats()
cust1.total_costumers()

cust2.display_stats()
cust2.total_costumers()
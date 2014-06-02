require 'matrix'

def multMatrixObject(matrix1, matrix2)
	return matrix1*matrix2
end


def multMatrix(matrix1, matrix2)
	n = matrix1.length
	mat = Array.new(n){Array.new(n){ 0 }}

	0.upto(n-1) do |i|
		0.upto(n-1) do |j|
			0.upto(n-1) do |k|
				mat[i][j] += matrix1[i][k] * matrix2[k][j]
			end
		end
	end

	return mat
end


n = ARGV.at(0).to_i


mat1 = Array.new(n){Array.new(n){ 0 }}
mat2 = Array.new(n){Array.new(n){ 0 }}

0.upto(n-1) do |i|
	0.upto(n-1) do |j|
		mat1[i][j] = (i+1)+(j+1);
		mat2[i][j] = (i+1)*(j+1);
	end
end

puts multMatrix(mat1, mat2)


=begin
mat1 = Matrix.build(n, n) {|row, col| (col+1)+(row+1) }
mat2 = Matrix.build(n, n) {|row, col| (col+1)*(row+1) }
puts multMatrixObject(mat1, mat2)
=end
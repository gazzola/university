// Ast::Abstract Syntax Tree

#include <iostream>
#include <memory>


namespace Ast{


	class ANode {


		public:
			int lineNumber, value;

			ANode(){};
			ANode(int l){ 
				this->lineNumber = l;
			};
			
			virtual ~ANode(){};

			virtual void print(){
				std::cout << this->lineNumber << std::endl;
			};

			virtual void eval(){};
	};




	class UnaryOperation : public ANode{
		int type;
		std::unique_ptr<ANode> child;
	};

	

	class IntNode : public ANode{
		public:
			int value;
			IntNode(int value){
				this->value = value;
			};

			virtual ~IntNode(){};
	};


	class Operation : public ANode{

		public:
			int type;
			std::unique_ptr<ANode> left;
			std::unique_ptr<ANode> right;
			std::unique_ptr<ANode> lvalue;

			Operation(ANode *x, int type, ANode *y){
				this->type = type;
				std::cout << x->value + y->value << std::endl;
				this->left = std::unique_ptr<ANode>(x);
				this->right = std::unique_ptr<ANode>(y);
			};

			void eval(){
				
				int x = this->left->value;
				int y = this->right->value;
				// this->lvalue = new std::unique_ptr<IntNode>(x+y);
				std::cout << x + y << std::endl;
			}

			virtual ~Operation(){};

	};

	class FloatNode : public ANode{
		float value;
	};

	class CharNode : public ANode{
		char value;
	};

	class BoolNode : public ANode{
		bool value;
	};

	class IdNode : public ANode{
		std::string id;
		std::shared_ptr<ANode> value;
	};

	class ArrayNode : public IdNode{
		int index;
	};

};



int main(){

	Ast::IntNode *i = new Ast::IntNode(25);
	Ast::IntNode *j = new Ast::IntNode(22);
	Ast::Operation *u = new Ast::Operation(i, 0, j);
	u->eval();

	return 0;
}
#include<string>
#include<functional>
#include<iostream>

using namespace std;

template<typename T>
class Node {
    public:
        string value;
        string next_input;
        T t;

    Node<T>(string value, string next_input) : value(value), next_input(next_input) { };
    
    Node<T>(string value, string next_input, const T& object) : value(value), next_input(next_input), t(object) {};    

    void display() {
        cout << "Node(" << "v " << value << " n " << next_input << " ";
        cout << "t " << t << ")\n";
    }

    bool exists() {
        return !value.empty();
    }
};

template<typename T>
class And;

template<typename T>
class Or;

template<typename T>
class Combinator {
    public:

    And<T> operator&(Combinator<T>& combinator) {
        return And<T>(this, &combinator);
    }

    Or<T> operator|(Combinator<T>& combinator) {
        return Or<T>(this, &combinator);
    }

    virtual Node<T> parse(string input) {
        cout << input;
        cout << "e";
        return Node<T>("", input);
    }
};

template<typename T>
class Literal : public Combinator<T> {
    private:
        string value;

    public:

    Literal(string value) : value(value) {};

    virtual Node<T> parse(string input) {
        if(input.substr(0, value.length()) == value) {

            return Node<T>(value, input.substr(value.length(), input.length() - value.length()));
        }
        else {
            return Node<T>("", input);
        }
    }
};

template<typename T>
class And : public Combinator<T> {
    private:
        Combinator<T>* parser;
        Combinator<T>* other;

    public:

    And(Combinator<T>* parser, Combinator<T>* other) : parser(parser), other(other) {};
    
    virtual Node<T> parse(string input) {
        cout << input;int t; cin >> t;
        
        Node<T> result = parser->parse(input);
        result.display();
        if(result.exists()) {
            Node<T> result_other = other->parse(result.next_input);
            if(result_other.exists()) {
                return Node<T>(result.value + result_other.value, result_other.next_input, result.t + result_other.t);
            }
        }
        return Node<T>("", input);
    }
};

template<typename T>
class Or : public Combinator<T> {
    private:
        Combinator<T>* parser;
        Combinator<T>* other;

    public:

    Or(Combinator<T>* parser, Combinator<T>* other) : parser(parser), other(other) {};

    virtual Node<T> parse(string input) {
        Node<T> result = parser->parse(input);
        if(!result.exists()) {
            result = other->parse(input);
            if(!result.exists()) {
                return Node<T>("", input);
            }
        }
        return result;
    }
};

template<typename T>
class Apply : Combinator<T> {
    private:
        Combinator<T>* parser;
        function<T(Node<T>)> block;

    public:

    Apply(Combinator<T>* parser, function<T(Node<T>)> block) : parser(parser), block(block) {};
    
    virtual Node<T> parse(string input) {
        Node<T> result = parser->parse(input);
        if(result.exists()) {
            T fix = f(result);
            result.t = fix;
        }
        return result;
    }
};

int main() {
    auto a = Literal<string>("b");
    auto z = Literal<string>("a");
    auto parser = a & z & a;
    auto result = parser.parse("baba");
    result.display();
}





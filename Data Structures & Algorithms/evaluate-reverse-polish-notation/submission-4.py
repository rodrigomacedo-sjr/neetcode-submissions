class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token == "+":
                b = stack.pop()
                a = stack.pop()
                stack.append(a + b)
                print(a, " + ", b, " = ", a + b)
                print(stack)
            elif token == "-":
                b = stack.pop()
                a = stack.pop()
                stack.append(a - b)
                print(a, " - ", b, " = ", a - b)
                print(stack)
            elif token == "*":
                b = stack.pop()
                a = stack.pop()
                stack.append(a * b)
                print(a, " * ", b, " = ", a * b)
                print(stack)
            elif token == "/":
                b = stack.pop()
                a = stack.pop()
                stack.append(int(a / b))
                print(a, " / ", b, " = ", a // b)
                print(stack)
            else:
                stack.append(int(token))
                print("add " + token)
                print(stack)
        return stack.pop()

        
class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def add(self, value):
    	if self.left and value < self.left.value:
    		self.left.add(value)
    	elif self.right and value > self.right.value:
    		self.right.add(value)
    	else:
    		if self.value < value:
    			if self.left:
    				self.left.add(self.value)
    			else:
    				self.left = BinaryTree(self.value)
    		else:
    			if self.right:
    				self.right.add(self.value)
    			else:
    				self.right = BinaryTree(self.value)
    		self.value = value

    def find(self, value):
    	if value > self.value and self.right:
    		return self.right.find(value)
    	elif value < self.value and self.left:
    		return self.left.find(value)
    	else:
    		if value == self.value:
    			return self
    		else:
    			return None

    def __str__(self):
    	return self.as_string(0)

    def as_string(self, depth):
    	return "%s%s\n%s%s\n" % (
    		' ' * depth,
    		self.value,
    		self.right.as_string(depth + 1) if self.right else '',
    		self.left.as_string(depth + 1) if self.left else '')
    
    __repr__ = __str__

b = BinaryTree(2.2)
print(b)
b.add(-2)
print(b)

print(b.find(-2))


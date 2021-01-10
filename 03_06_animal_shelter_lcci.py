# https://leetcode-cn.com/problems/animal-shelter-lcci/

class AnimalShelf:

	def __init__(self):
		self.cat = []
		self.dog = []

	def enqueue(self, animal:List[int]) -> None:
		if animal[1] == 0:
			self.cat.append(animal[0])
		else:
			self.dog.append(animal[0])

	def dequeueAny(self) -> List[int]:
		if len(self.cat) != 0:
			if len(self.dog) == 0:
				idx = self.cat.pop(0)
				ani = 0
			else:
				if self.cat[0] < self.dog[0]:
					idx = self.cat.pop(0)
					ani = 0
				else:
					idx = self.dog.pop(0)
					ani = 1
		else:
			if len(self.dog) == 0:
				idx = -1
				ani = -1
			else:
				idx = self.dog.pop(0)
				ani = 1
		return [idx,ani]

	def dequeueDog(self) -> List[int]:
		if len(self.dog) == 0:
			idx = -1
			ani = -1
		else:
			idx = self.dog.pop(0)
			ani = 1
		return [idx,ani]

	def dequeueCat(self) -> List[int]:
		if len(self.cat) == 0:
			idx = -1
			ani = -1
		else:
			idx = self.cat.pop(0)
			ani = 0
		return [idx,ani]
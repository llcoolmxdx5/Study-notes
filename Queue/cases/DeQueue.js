class DeQueue {
  constructor() {
    this.count = 0;
    this.lowestCount = 0;
    this.items = {};
  }
  clear() {
    this.count = 0;
    this.lowestCount = 0;
    this.items = {};
  }
  size() {
    return this.count - this.lowestCount;
  }
  isEmpty() {
    return this.size() === 0;
  }
  toString() {
    if (this.isEmpty()) {
      return "";
    }
    return new Array(this.size())
      .fill("")
      .map((i, index) => this.items[this.lowestCount + index])
      .join(",");
  }
  addFront() {
    const length = [...arguments].length;
    new Array(length).fill("").forEach((i, index) => {
      this.items[this.lowestCount + length + index] = this.items[
        this.lowestCount + index
      ];
    });
    [...arguments].forEach((item, i) => {
      this.items[i] = item;
      this.count += 1;
    });
    this.lowestCount = 0;
  }
  addBack() {
    [...arguments].forEach((item) => {
      this.items[this.count] = item;
      this.count++;
    });
  }
}

const dequeue = new DeQueue();
dequeue.addBack(1, 2, 3);
dequeue.addFront(4, 5, 6);
console.log(dequeue.toString());
console.log(dequeue.size());

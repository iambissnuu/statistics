from collections import Counter

class StatisticsCalculator:
    def __init__(self, numbers):
        self.numbers = sorted(numbers)

    def mean(self):
        return sum(self.numbers) / len(self.numbers)

    def median(self):
        n = len(self.numbers)
        mid = n // 2
        if n % 2 == 0:
            return (self.numbers[mid - 1] + self.numbers[mid]) / 2
        return self.numbers[mid]

    def mode(self):
        frequency = Counter(self.numbers)
        max_count = max(frequency.values())
        modes = [num for num, count in frequency.items() if count == max_count]
        return modes

    def display_results(self):
        print("Numbers:", self.numbers)
        print(f"Mean: {self.mean():.2f}")
        print(f"Median: {self.median()}")
        print(f"Mode: {self.mode()}")


if __name__ == "__main__":
    sample_data = [2, 4, 4, 6, 8, 10, 4, 6]
    calculator = StatisticsCalculator(sample_data)
    calculator.display_results()

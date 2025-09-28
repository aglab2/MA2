import os

# Patterns to search for
star_patterns = [
    "bhvStar)",
    "bhvHiddenRedCoinStar)",
    "bhvHiddenStar)",
    "bhvCETimerStar)",
]

goal_patterns = [
    "bhvGoal)",
]

checkpoint_patterns = [
    "bhvCheckpoint)",
]

checkpoint_patterns_chao = [
    "bhvCheckpointChao)",
]

class StarCount:
    def __init__(self):
        self.stars = 0
        self.goals = 0
        self.checkpoints = 0
        self.chao_checkpoints = 0
    
    def total(self):
        return self.stars + self.goals + self.checkpoints + self.chao_checkpoints

    def __str__(self):
        parts = []
        if self.stars:
            parts.append(f"{self.stars} stars")
        if self.goals:
            parts.append(f"{self.goals} goals")
        if self.checkpoints:
            parts.append(f"{self.checkpoints} checkpoints")
        if self.chao_checkpoints:
            parts.append(f"{self.chao_checkpoints} chao checkpoints")
        return ", ".join(parts)

levels_dir = os.path.join(os.path.dirname(__file__), "..", "levels")

def count_matches_in_file(filepath):
    counts = StarCount()
    try:
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            for line in f:
                for pattern in star_patterns:
                    if pattern in line:
                        counts.stars += 1
                for pattern in goal_patterns:
                    if pattern in line:
                        counts.goals += 1
                for pattern in checkpoint_patterns:
                    if pattern in line:
                        counts.checkpoints += 1
                for pattern in checkpoint_patterns_chao:
                    if pattern in line:
                        counts.chao_checkpoints += 1
    except Exception:
        pass

    return counts

def main():
    results = {}
    total = 0
    for filename in os.listdir(levels_dir):
        filepath = os.path.join(levels_dir, filename, "script.c")
        count = count_matches_in_file(filepath)
        if not count.total():
            continue
        total += count.total()
        results[filename] = count

    print(f"Total: {total}")
    for dirname, count in sorted(results.items()):
        traits_line = f".stars = {count.stars}, .checkpoints = {count.checkpoints}"
        assert count.goals < 2, f"More than one goal found in {dirname}"
        if count.goals:
            traits_line += f", .goal = true"
        if count.chao_checkpoints:
            traits_line += f", .extra = true"

        print(f"[ COURSE_{dirname.upper()} ] = {{ {traits_line} }}")

if __name__ == "__main__":
    main()

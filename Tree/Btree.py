import sys

sys.setrecursionlimit(10**6)


# 노드
class BTreeNode:
    def __init__(self):
        self.values = []  # 노드에 저장된 값
        self.children = []  # 자식 노드


# 각 레벨의 노드와 해당 노드의 값을 출력
def print_tree(node, level=0):
    if node is not None:
        print(f"Level {level}: {node.values}")
        for child in node.children:
            print_tree(child, level + 1)


# B-Tree
class BTree:
    def __init__(self):
        self.root = BTreeNode()  # 루트 노드

    def insert(self, value):  # 값 삽입
        self.insert_value(self.root, value)

    def insert_value(self, node, value):
        # 현재 노드의 children 리스트가 비어있는지를 확인
        if not node.children:  # 현재 노드가 리프 노드인 경우 -> 값 삽입
            node.values.append(value)  # 삽입
            node.values.sort()  # 정렬

            if len(node.values) > 4:  # 노드가 가득 찼을 경우 -> 분할
                left_node = BTreeNode()  # 좌측 자식 노드
                right_node = BTreeNode()  # 우측 자식 노드
                left_node.values = node.values[:2]  # 중간값을 기준으로 분할
                right_node.values = node.values[3:]
                node.values = [node.values[2]]  # 중간값으로 값 갱신
                node.children = [left_node, right_node]  # 자식 노드

        else:  # 현재 노드가 부모 노드인 경우 자식 노드로 이동
            i = 0
            while i < len(node.values):  # value와 현재 노드의 values 리스트를 비교
                # value가 현재 노드의 values[i] 값보다 작다면,
                # 삽입할 value는 현재 노드의 values[i] 값보다 왼쪽에 있어야 함을 의미
                # 이 경우, while 루프를 탈출하고 i는 삽입할 value가 들어가야 하는 인덱스가 된다.
                if value < node.values[i]:
                    break
                i += 1
            self.insert_value(
                node.children[i], value
            )  # value를 자식 노드 중 i 인덱스에 해당하는 자식 노드로 이동

    def get(self, value):
        return self.get_value(self.root, value)

    def get_value(self, node, value):
        if not node.children:  # 현재 노드가 리프 노드인 경우
            return value in node.values
        else:  # 현재 노드가 부모 노드인 경우 자식 노드로 이동
            i = 0
            while i < len(node.values):
                if value == node.values[i]:
                    return True
                if value < node.values[i]:
                    return self.get_value(node.children[i], value)
                i += 1
            return self.get_value(node.children[i], value)


# B-Tree 생성
btree = BTree()

# # 값 삽입
# values_insert = [5, 2, 11, 6, 7, 8, 3, 10, 15]
# print("[5, 2, 11, 6, 7, 8, 3, 10, 15]를 삽입합니다.")
# for value in values_insert:
#     btree.insert(value)

# # 값을 검색
# values_find = [3, 10, 6]
# print("[3, 10, 6]값이 있는지 확인합니다.")
# for value in values_find:
#     found = btree.get(value)
#     if found:
#         print(f"{value}를 찾았습니다.")
#     else:
#         print(f"{value}를 찾지 못했습니다.")
# print("\nB-Tree 노드와 레벨을 확인합니다.")
# print_tree(btree.root)

# import random
# import time

# # 1. 0 ~ 1,000,000 범위에서 중복 없는 100,000개의 임의의 값 추출
# # values_insert = random.sample(range(1000001), 100000)

# values_insert = [i for i in range(10000)]
# values_insert.reverse()
# # 2. 0 ~ 1,000,000 범위에서 중복 없는 10,000개의 임의의 값 추출
# # values_find = random.sample(range(1000001), 10000)
# values_find = [i for i in range(10000)]

# # 3. List에 값을 삽입
# start_time = time.time()
# l = []
# for value in values_insert:
#     l.append(value)
# list_insert_time = time.time() - start_time

# # 4. B-Tree에 값을 삽입
# start_time = time.time()
# btree = BTree()
# for value in values_insert:
#     btree.insert(value)
# btree_insert_time = time.time() - start_time

# # 5. List에서 값의 존재 확인 및 시간 측정
# start_time = time.time()
# for value in values_find:
#     found = value in l
#     """
#     if found:
#         print(f"{value}를 찾았습니다.")
#     else:
#         print(f"{value}를 찾지 못했습니다.")
#     """
# list_find_time = time.time() - start_time

# # 6. B-Tree에서 값의 존재 확인 및 시간 측정
# start_time = time.time()
# for value in values_find:
#     found = btree.get(value)
# btree_find_time = time.time() - start_time

# print("\nList와 B-Tree의 소요시간을 출력합니다.")
# print(f"List 소요 시간: {abs(list_find_time - list_insert_time)} 초")
# print(f"B-Tree 소요 시간: {abs(btree_find_time - btree_insert_time)} 초")

import sys

stdin = [50, 30, 24, 5, 28, 45, 98, 52, 60]


def main():
    # 표준 입력에서 모든 줄을 읽어서 정수로 변환
    input_lines = sys.stdin.readlines()
    preorder_traversal = list(map(int, input_lines))

    # 스택 초기화: (현재 노드 값, 부모 노드의 최대 값)을 저장
    node_stack = [(float("inf"), float("inf"))]

    # 전위 순회 결과를 처리
    for node_value in preorder_traversal:
        # 현재 노드 값이 부모 노드의 최대 값보다 작으면 스택에 추가
        if node_value < node_stack[-1][0]:
            node_stack.append((node_value, node_stack[-1][0]))
        else:
            # 현재 노드가 부모 노드의 최대 값보다 클 때까지 스택에서 팝하고 출력
            while node_value > node_stack[-1][1]:
                print(node_stack.pop()[0])
            # 현재 노드를 스택에 추가
            node_stack.append((node_value, node_stack[-1][1]))

    # 스택에 남은 노드들을 팝하면서 출력
    while len(node_stack) > 1:
        print(node_stack.pop()[0])


main()

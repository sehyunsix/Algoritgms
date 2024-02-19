map = np.array([[1,1,0,1],[1,1,0,1],[1,0,0,1],[1,1,1,0]])

# find_blocks
def find_block_position(map):
  bolcks_position = []
  block_idx = np.where(map==0)
  visited = np.zeros(map.shape)
  block_idx = [ x for i,x in enumerate(zip(block_idx[0],block_idx[1]))]
  for start in  block_idx:
    stack = [start]
    block= []
    #block_making
    while stack:
      print(stack)
      current = stack.pop()
      block.append([current[0],current[1]])
      visited[current[0]][current[1]]=1
      d=[[1,0],[0,1],[-1,0],[0,-1]]
      nexts= [[current[0]+i[0],current[1]+i[1]] for i in d]
      for next in nexts:
        if next[0]>=0 and next[0]<map.shape[0] and next[1]>=0 and next[1]<map.shape[1] and visited[next[0]][next[1]]==0:
          if map[next[0]][next[1]]==0:
            stack.append(next)
            #why? here
            block_idx.remove((next[0],next[1]))
    #append blocks
    bolcks_position.append(block)
  return bolcks_position,visited,block_idx

def title_hash_by_position(blocks_position):
  min_y =min([tile[0] for tile in blocks_position])
  max_y =max([tile[0] for tile in blocks_position])
  min_x =min([tile[1] for tile in blocks_position])
  max_x =max([tile[1] for tile in blocks_position])
  tile_representations = [
    tuple(
        tuple([j,i] in blocks_position for j in range(min_y, max_y + 1))
        for i in range(min_x, max_x + 1)
    )
    ]
  def rotate90(tile):
    return np.rod90(tile)
  for __ in range(3):
        tile_representations.append(rotate90(tile_representations[-1]))

  return min(tile_representations)
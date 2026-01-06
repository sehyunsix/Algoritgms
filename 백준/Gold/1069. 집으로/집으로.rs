
fn main() {

    let mut input = String::new();

    std::io::stdin()
        .read_line(&mut input)
        .unwrap();

    let mut parts = input.split_whitespace();
    let x :i32= parts.next().unwrap().parse().expect("couldn't parse integer");
    let y :i32= parts.next().unwrap().parse().expect("couldn't parse integer");
    let d :i32= parts.next().unwrap().parse().expect("couldn't parse integer");
    let t :i32= parts.next().unwrap().parse().expect("couldn't parse integer");

    // println!("{x},{y},{d},{t}");

    // 최소거리가 가장 빠른길일까? 아니다 왼쪽으로 한번가면서 D칸 맞춰놓으면, 더 빨리 갈수도 있다.
    // D칸으로 갈떄, D/T >1 이면 반드시 빠르다. 점프로가는 것이 반드시 빠르다.
    // 모든 경우의 수는 얼마나 될까  X,Y <1000 이상이고 D로4가지 경우가 있다
    // D를 몇번 쓰는지 알아야한다.
    // 각 좌표마다 빨리 갈 수 있는 초를 기입하면 빠를 거 같다. 그러면 그 좌표를 건너가려면 그방법을쓰는게 맞기 떄문이다. 그렇게 BFS로 다 탐색하면 나오지앟을까.
    // 어떻게 각좌표를 가장 빠르게 갈 수 있는 방법으로 저장할 수 있을까.
    // 0 0 에서 출발해서 가장 빠르게 갈 수 있는 길을 찾는 방법은 어덜까.
    // 예를들면 1일때 갈 수 있는 길은 자명하다. 2일때 갈 수있는 길도 자명하다. 그런데 t초맏는 D칸으로 갈 수 있다.
    // 매초마다 갈 수 있는 거리를 표시하면. visited로 표시된 칸들은 최소라는게 보장된다.
    // 그럼 로직을 생각해보자. 점프를 안쓸수 있으니가 최외각 loop는 X+Y로 제한된다. 이 제한되는 시간동안 갈 수 있는 지역에 visitied를 표시하는거다.
    // 그러면 매 loop마다 어떻게 칠해질 수 있을까를 고민해보자. 각 점들의 4면을 계쏙 보면도니다.최소 4000개다. 2000*4000 충분하다.시간은 충분하다.
    // 그러면 모든 지역을 다 볼 수 있다.

    //매초마다찾는 것은 ㄴ무리가 있다 1초에 1만큼 간다는것이 속도의 이야기다. 이거 넘어서 0,0 넘어서도 갈 수 잇다.
    // 모든 좌표에 빠른 도착시간을 표시할 순 없다.
    // 문제를 나눠보자자. t가 만약 1이라면?
    // 직선을 생각해보자. 갈 수 있는 직선은 얼마나 있을까.
    // 걸을 꺼면 그냥 그 위치와 점사이의 거리다.
    // 걷지 않는다면? 어느 x,y 지점에서  0까지 가려면 어느방향으로 해야할까
    // 점프의 거리가 고정되어 있다는 것에 주의해보자.
    // 점과 원점사이의 거리, 그리고 점프의 거리가 모든 것을 결정한다.
    // X,y는 버려도 된다.
    // 점프를 한번 사용하는 위치는 반드시 t이상인 지역이여야함.
    // 점프를 두번 사용하는 위치는?
    // d < D
    // \ D- d| < k
    // d > D
    // d-n*D+n*t
    // n*t (어떤 길이든 만들어 낼수 있음. 두번이면) 두번쓰면 가능함. (n+1)*D >d 라면 (n+1)t까지는 가능하다.
    // 자 그러면 나머지는 없다.?
    // d = D
    //
    // w = D

    // 답의경우
    // (n+1)*t (모두 점프만 하는 경우)
    // nt* (d-D*n) 점프하고 걸은 경우
    // d 걷기만 한 경우
    let mut k:f64 = (x*x+y*y).into();
    k = k.sqrt();
    let mut n = (k/d as f64).floor();

    if (n==0.0){
        n=1.0;
    }

    let diff:f64 =k-(n*d as f64);
    let mut alpha = 0.0;
    if diff<0.0000001  && -0.0000001 < diff{
        alpha = 1.0;
    }
    // println!("n: {n} alpha: {alpha}");
    let mut sol:f64 = ((n+1.0-alpha)*t as f64).min(diff.abs()+n*t as f64).into();
    sol = sol.min(k);

    println!("{}",sol);
}
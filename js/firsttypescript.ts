let a: String = "hello";
type Dir = "north" | "south" | "west" | "east";
type Direction = Dir | Uppercase<Dir> | Capitalize<Dir>;
const echoDir = (value: Direction) => {
  console.log(value);
};
echoDir("north");
echoDir("EAST");
echoDir("South");
export default a;
export { echoDir };

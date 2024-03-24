type user = {
    _id : string;
    name : string;
}
type UserLogin = user & {password: string};
const userLogin: UserLogin = {
    _id: "123",
    name: "Chance",
    password: "235"
}
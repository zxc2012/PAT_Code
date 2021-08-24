import React,{component}from 'react';
class Comment extends component{
    constructor(props){
        super(props);//calls on the component's super class constructor
                    //converts this javascript class into a react component
        state={
            isLiked:false,
        }
    }
    likeComment=()=>{
        this.setstate=({
            isLiked=true,
        });
    }
    render(){
        return(
            <div id="coolcomment" className="comment-text" onClick={this.likeComment}>
                {this.props.content}
                {this.setstate.isLiked?<LikeButton />:null}
            </div>
        );
    }
}
export default Comment;
setTimeout()
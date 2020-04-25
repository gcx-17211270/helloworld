package graph;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月25日 上午3:14:37
*@deprecated 代码7-2 UnsupportedOperation 异常
*UnsupportedOperation 是调用图不支持的操作时抛出的异常，定义如下
*/

public class UnsupportedOperation extends RuntimeException {

	public UnsupportedOperation() {
		// TODO Auto-generated constructor stub
	}

	public UnsupportedOperation(String message) {
		super(message);
		// TODO Auto-generated constructor stub
	}

	public UnsupportedOperation(Throwable cause) {
		super(cause);
		// TODO Auto-generated constructor stub
	}

	public UnsupportedOperation(String message, Throwable cause) {
		super(message, cause);
		// TODO Auto-generated constructor stub
	}

	public UnsupportedOperation(String message, Throwable cause, boolean enableSuppression,
			boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
		// TODO Auto-generated constructor stub
	}

}
